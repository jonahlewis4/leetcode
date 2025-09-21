class MovieRentingSystem {
    struct Entry {
        int shop;
        int movie;
        int price;
    };

    typedef set<const Entry*, decltype([](const Entry* a, const Entry* b){
        if(a->price < b->price){
            return true;
        }
        if(a->price > b->price) {
            return false;
        }
        return a->shop < b->shop;
    })> searchSetType; 
    //shop then movie
    unordered_map<int, unordered_map<int, Entry>> gMap;
    unordered_map<int, searchSetType> searchSets;
    unordered_map<int, unordered_map<int, searchSetType::iterator>> rentDropHandler;

    typedef set<const Entry*, decltype([](const Entry* a, const Entry* b){
        if(a->price < b->price) {
            return true;
        }
        if(a->price > b->price) {
            return false;
        }
        if(a->shop < b->shop) {
            return true;
        }
        if(a->shop > b->shop) {
            return false;
        }
        return a->movie < b->movie;
    })> rentSetType;

    rentSetType rentSet;
        
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(const auto & e : entries) { 
            //add entry to global map
            int shop = e[0];
            int movie = e[1];
            int price = e[2];
            Entry newE = {
                .shop = shop,
                .movie = movie,
                .price = price
            };

            gMap[shop][movie] = newE;
            const Entry* ePtr = &gMap[shop][movie];
    
            //add entry ref to searchMap
            const auto &[insertedItr, _] = searchSets[movie].insert(ePtr);
            //add inserted iterator to rent/drop handler
            rentDropHandler[shop][movie] = insertedItr;

        }
        
    }
    
    vector<int> search(int movie) {
        //return shops first 5 entries in searchMap
        searchSetType::iterator itr = searchSets[movie].begin();
        vector<int> res;
        
        for(int i = 0; i < 5; i++) {
            if(itr == searchSets[movie].end()){
                break;
            }
            const Entry* e = *itr;
            res.push_back(e->shop);
            itr++;
        }
        
        return res;
    }
    
    void rent(int shop, int movie) {
        //remove iterator gotten from rent/drop handler
        searchSetType::iterator itr = rentDropHandler[shop][movie];
        searchSets[movie].erase(itr);
        //remove rent/drop handler value
        rentDropHandler[shop].erase(movie);
        //add rented movie to rentSet
        const Entry* ePtr = &gMap[shop][movie];
        rentSet.insert(ePtr);
        //optional: clear whole thing of shop if empty
        if(rentDropHandler[shop].empty()){
            rentDropHandler.erase(shop);
        }
    }
    
    void drop(int shop, int movie) {
        const Entry* ePtr = &gMap[shop][movie];
        //get iterator from inserting into searchMap
        const auto &[insertedItr, _] = searchSets[movie].insert(ePtr);
        //add that iterator to rent/drop handler value
        rentDropHandler[shop][movie] = insertedItr;
        //remove rented movie from rentSet
        rentSet.erase(ePtr);
    }
    
    vector<vector<int>> report() {  
        vector<vector<int>> res;
        rentSetType::iterator itr = rentSet.begin();
        for(int i = 0; i < 5; i++) {
            if(itr == rentSet.end()){
                break;
            }
            const Entry* ePtr = *itr;
            res.push_back({
                ePtr->shop,
                ePtr->movie
            });
            itr++;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
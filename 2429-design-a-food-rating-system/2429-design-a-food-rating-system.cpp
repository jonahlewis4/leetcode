class FoodRatings {
private: 
    unordered_map<string, map<int, set<string>>> ratesOfCuisine;
    unordered_map<string, string> cuisineOf;
    unordered_map<string, int> ratingOf;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            const string& food = foods[i];
            const string& cuisine = cuisines[i];
            const int rating = ratings[i];

            cuisineOf[food] = cuisine;
            ratingOf[food] = rating;
            ratesOfCuisine[cuisine][rating].insert(food);
            
        }
    }
    
    void changeRating(string food, int newRating) {
        const string& cuisine = cuisineOf[food];
        const int rating = ratingOf[food];
        set<string>& ratings = ratesOfCuisine[cuisine][rating];
        ratings.erase(food);
        if(ratings.empty()){
            ratesOfCuisine[cuisine].erase(rating);
        }

        ratingOf[food] = newRating;
        ratesOfCuisine[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        const set<string>& highestRatedFoods = ratesOfCuisine[cuisine].rbegin()->second;
        return *highestRatedFoods.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
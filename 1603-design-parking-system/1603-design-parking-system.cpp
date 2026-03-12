class ParkingSystem {
private:
    int _big;
    int _medium;
    int _small;
public:
    ParkingSystem(int big, int medium, int small) {
        _big=big;
        _medium=medium;
        _small=small;
    }
    
    bool addCar(int carType) {
        int* ptr;
        switch (carType) {
            case 1: {
                ptr = &_big;
                break;
            }
            case 2 : {
                ptr = &_medium;
                break;
            }
            case 3: {
                ptr = &_small;
                break;
            }
        }
        
        if((*ptr) == 0) {
            return false;
        }

        (*ptr)--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
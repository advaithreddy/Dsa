#include<iostream>
#include<unordered_map>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;

class RandomizedSet{
private:
    unordered_map<int,int> mp;
    vector<int> s;

public:

    RandomizedSet(){
        // Constructor
        srand(time(0)); // Seeds random generator
    }

    bool insert(int val){
        // Checking
        if(mp.find(val)!= mp.end()){
            // It exist 
            return false;
        }

        s.push_back(val);
        mp[val] = s.size()-1; // This will inser the index into the map
        return true;
    }

    bool remove(int val){
        // Checking
        if(mp.find(val) == mp.end()){
            return false; // The number doesn't exist
        }

        int index = mp[val]; // get the index
        int lastele = s.back();   // get the last element this is random like we can insert any
        // number i choose the last casue it can be handy

        // Change it in the array
        s[index] = lastele;    // now the ele has been the changed i.e the val has been removed
        
        // Now change the index in map
        mp[lastele] = index;

        // Now pop off
        s.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom(){
        int randomIndex = rand() % s.size(); // By this the random index will be in the range of 
        // the size of the array
        return s[randomIndex];
    }
};

signed main(){

    RandomizedSet mySet;

    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    std::cout << "Random element: " << mySet.getRandom() << std::endl;

    mySet.remove(2);

    std::cout << "Random element after removal: " << mySet.getRandom() << std::endl;

    return 0;

    return 0;
}
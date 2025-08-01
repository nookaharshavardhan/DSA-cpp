#include <iostream>
using namespace std;

int minBitsToFlip(int start ,int goal){
    int bits_to_be_flipped = 0;
    for(int i = 0; i < 32;i++){
        if(  ( (start >> i) & 1) != ((goal >> i) & 1)){      //  comparing all bits one by one and incresing count if there is a different bit.
            bits_to_be_flipped++;
        }
    }
    return bits_to_be_flipped;
}

int count_set_bits(int num){
    int no_of_set_bits = 0;
    while(num != 0){
        num &= (num-1);
        no_of_set_bits++;
    } 
    return no_of_set_bits;
}

int minBitsToFlip_optimized(int start,int goal){
    int set_diff_bits_to_1 = start ^ goal;       // diff bits are set to 1 so counting 1 is enough
    return count_set_bits(set_diff_bits_to_1);
}


int main() {
    int start = 3;
    int goal = 4;
    cout<<"min bits to flip is "<<minBitsToFlip_optimized(start,goal);
    return 0;
}
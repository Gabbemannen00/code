#include <iostream>
using namespace std;
/*

Felsök och åtgärda följande kod. Förklara varje fel du hittar och hur du åtgärdade det: 

int main() {
    double temperatures[] = {98.6, 99.2, 97.9, 100.1, 98.8; 
    double average;
    
    for(int i = 0; i <= 4; i++) {
        average += temperatures[i];
    }
    
    cout << "The average temperature is: " << average/4;
}
*/

/*fel på rad 8: saknas en '}' i slutet av arrayen. Dessutom har ingen storlek på arrayen har angetts.

fel på rad 9: variabeln average har inget startvärde vilket kan leda till felaktiga utmatningar.

fel på rad 11: for loopen är inställd på att iterera över bara 4 element när det finns 5 stycken i arrayen.

fel på rad 40: Saknades ett return 0; statement i main funktionen.
*/

//rättad kod:

int main() {

    double temperatures[5] = {98.6, 99.2, 97.9, 100.1, 98.8}; //satte in en }' i slutet, angav storleken på arrayen till 5.
    double average = 0.0; //la in ett startvärde 0.0 eftersom det är en double. 
    
    for(int i = 0; i < 5; i++) { //böt ut 4 till 5 så att for-loopen itererar över talen som ligger mellan i 0 och i 4.
        average += temperatures[i];
    }
    
    cout << "The average temperature is: " << average/5;

    return 0;
}




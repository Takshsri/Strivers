#include <iostream>
#include <string>
using namespace std;
string RemoveHash(string txt){
    string text ="";
    for(int i=0;i<txt.size();i++){
        if(txt[i]=='#'){
            if(!text.empty())
            text.pop_back();
        }
        else{
            text+=txt[i];
        }
    }
    return text;

}
bool userLogic(string bob, string alice) {
    string bobText= RemoveHash(bob);
    string aliceText = RemoveHash(alice);
    return (bobText == aliceText)? true:false;
}

int main() {
    string bob, alice;
    getline(cin, bob);
    getline(cin, alice);
    bool result = userLogic(bob, alice);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}
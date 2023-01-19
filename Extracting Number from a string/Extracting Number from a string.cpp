#include <iostream>
#include <sstream>
using namespace std;

void extractIntegerWords(string str)
{
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    
    while (ss>>found) {

        /* extracting word by word from stream */
        cout << found << endl;
    }
    cout<<endl;
}

// Driver code
int main()
{
    string str;
    /*while(1){
        getline(cin, str);
        if(str == ""){
            break;
        }
        extractIntegerWords(str);
    }*/
    stringstream ss;
    int n;
    ss << "10 ";
    ss << "20";

    while(ss>>n) cout << n << endl;
    return 0;
}

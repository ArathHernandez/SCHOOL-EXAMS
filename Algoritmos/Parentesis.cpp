#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool esValido(string s) {
        if(s.length()<2) return false;
        
        stack<char>respuesta;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[') respuesta.push(s[i]);
            else{
                if (respuesta.empty()) return false;
                if(s[i] == ')' && respuesta.top() != '(')
                return false;
                else if(s[i] == ']' && respuesta.top() != '[') return false;
                
                respuesta.pop();
            }
        }
        return respuesta.empty();
    }

int main(){
    string s; cin >> s;
    cout << esValido(s) << endl;
}

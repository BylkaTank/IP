#include <iostream>
#include <string>

using namespace std;

string get_address_part(string ip, int octet){
    string part = "";
    int point = 0;
    for(int i = 0; i < ip.length(); i++){
        part += ip[i];
        if (ip[i] == '.'){
            if(point == octet){
                part.erase(part.length() - 1,1);
                return part;
            } else {
                part = "";
                point++;
            }
        }
    }
}

string IPv4(string ip){
    int point = 0;
    for(int i = 0; i < ip.length(); i++){
        if ((ip[i] < '0' || ip[i] > '9') && ip[i] != '.'){
            return "Invalid";
        } else if (ip[i] == '.' ) {
            point++;
            if (point > 3 || ip[i - 1] == '.'){
                return "Invalid";
            }
        }
    }

    for(int i = 0; i < 4; i++){
        int octet = 0;
        string part = get_address_part(ip,i);
        if(part.length() > 3){
            return "Invalid";
        } else {
            if(part.length() == 3) octet += ((part[0] - '0') * 100) + ((part[1] - '0') * 10) + (part[2] - '0');
            else if (part.length() == 2) octet += ((part[0] - '0') * 10) + (part[1] - '0');
            else octet +=  part[0] - '0';
        }

        if (part.length() - 1 == 2){
            if (part[0] == '0') return "Invalid";
        } else if (part.length() - 1 == 1){
            if (part[0] == '0') return "Invalid";
        }

        if (octet > 255) return "Invalid";
    }
    return "Valid";
}

int main() {
    string ip;
    cout << "Enter the ip: " << endl;
    cin >> ip;
    cout << IPv4(ip);
}

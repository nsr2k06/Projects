#include <bits/stdc++.h>
using namespace std;

// small common passwords list (can expand)
const vector<string> common_pw = {
    "123456","password","12345678","qwerty","abc123","111111","iloveyou","admin"
};

double log2d(double x){ return log(x)/log(2.0); }

int poolSize(const string &s){
    bool lower=0, upper=0, digit=0, special=0;
    for(char c: s){
        if(islower(c)) lower=1;
        else if(isupper(c)) upper=1;
        else if(isdigit(c)) digit=1;
        else special=1;
    }
    int pool = 0;
    if(lower) pool += 26;
    if(upper) pool += 26;
    if(digit) pool += 10;
    if(special) pool += 32; // approx printable specials
    return pool;
}

double estimateEntropy(const string &s){
    int pool = poolSize(s);
    if(pool==0) return 0.0;
    return s.length() * log2d(pool);
}

string breachCheck(const string &s){
    string low = s; transform(low.begin(), low.end(), low.begin(), ::tolower);
    for(const string &c: common_pw){
        if(low == c) return "FOUND in small-common-list (very weak)";
    }
    return "Not found in small list";
}

vector<string> suggestions(const string &s){
    vector<string> out;
    if(s.length() < 8) out.push_back("Increase length (>= 12 is better).");
    bool hasLower=false, hasUpper=false, hasDigit=false, hasSpec=false;
    for(char c: s){
        if(islower(c)) hasLower=true;
        else if(isupper(c)) hasUpper=true;
        else if(isdigit(c)) hasDigit=true;
        else hasSpec=true;
    }
    if(!hasUpper) out.push_back("Add uppercase letters (A,B,C...).");
    if(!hasDigit) out.push_back("Add digits (0-9).");
    if(!hasSpec) out.push_back("Add special chars (!@#...).");
    if(out.empty()) out.push_back("Password looks varied. Consider increasing length.");
    return out;
}

string rating(double bits){
    if(bits < 28) return "Very Weak";
    if(bits < 36) return "Weak";
    if(bits < 60) return "Moderate";
    return "Strong";
}

int main(){
    cout<<"Entropy-based Password Advisor\n";
    cout<<"Enter password: ";
    string pw;
    getline(cin, pw);
    double ent = estimateEntropy(pw);
    cout<<"\nEstimated Entropy (bits): "<<fixed<<setprecision(2)<<ent<<"\n";
    cout<<"Rating: "<<rating(ent)<<"\n";
    cout<<"Breach check: "<<breachCheck(pw)<<"\n\n";
    cout<<"Auto-suggestions:\n";
    auto s = suggestions(pw);
    for(size_t i=0;i<s.size();++i) cout<<i+1<<". "<<s[i]<<"\n";
    cout<<"\nExample stronger password idea (do NOT use exactly this): ";
    // quick auto-make: base + add complexity
    string sample = pw;
    if(sample.length() < 12) sample += "A1!";
    else sample[0] = toupper(sample[0]);
    cout<<sample<<"\n";
    return 0;
}

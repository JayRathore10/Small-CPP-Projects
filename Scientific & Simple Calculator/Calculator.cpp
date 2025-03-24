#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>
#include<windows.h>

#define PI 3.1415926535897932384

using namespace std;

void delayStyle();

void intro(char ch);

void simpleCal();

void sciCal(); 

vector<double> getIn();

// degree to Randain
inline double toRad(auto degree){
    return degree * PI/180.0; 
}

class Calculator{
public:
    template<typename... Args>
    auto add(Args... args){
        return (args + ...);
    }

    template<typename... Args>
    auto sub(Args... args){
        double arr[] = {args...};
        auto result = arr[0];
        for(int i = 1; i<sizeof...(args) ; i++){
            result -= arr[i];
        } 
        return result;
    }

    template<typename... Args>
    auto mul(Args... args){
        return (args * ...);
    }

    template<typename... Args>
    double div(Args... args){
        double arr[] = {static_cast<double>(args)...};
        double result = arr[0];
        for(int i = 1 ; i<sizeof...(args) ; i++){
            if(arr[i] == 0){
                cerr <<"Error : try to divide by Zero "<<endl;
                return 0 ;
            }
            result /= arr[i];
        }
        return result;
    }
};

class SciCal : public Calculator{
public:
    auto root(auto num){
        return (sqrt(num));
    }

    auto power(auto base , auto exp){
        return(pow(base , exp));
    }

    auto logBase10(auto num){
        return (log10(num));
    }

    auto logBaseN(auto num){
        return (log(num));
    }

    auto sinR(auto degree){
        return (sin(toRad(degree)));
    }

    auto cosR(auto degree){
       return (cos(toRad(degree)));
    }

    auto tanR(auto degree){
        return(tan(toRad(degree)));
    }

    auto aSinR(auto x){
        return (asin(x));
    }

    auto aCosR(auto x){
        return (acos(x));
    }

    auto atanR(auto x){
        return (atan(x));
    }

};

int main(){
    char ch ;
    delayStyle();
    cout<<setw(75)<<"CALCULATOR"<<endl;
    delayStyle();
    cout<<endl<<endl;
    cout<<setw(80)<<"C/c : Simple Calculaor "<<endl;
    cout<<setw(85)<<"S/s : Scientific Calculator "<<endl;
    cout<<setw(67)<<"Q/q : Exit"<<endl;
   
    while(1){
        cout<<setw(1)<<"-> ";
        cin>>ch;
        if(tolower(ch) == 's'){
            intro(ch);
            sciCal();
            break;
        }else if (tolower(ch) == 'c'){
            intro(ch);
            simpleCal();
            break;
        }else if (tolower(ch) == 'q'){
            delayStyle();
            cout<<setw(78)<<"Calculator OFF"<<endl;
            delayStyle();
            return 0;
        }else{
            cout<<"You enter the invalid input , Enter Agian"<<endl;
        }
    }
    return 0;
}

// animation heading 
void delayStyle(){
    const int delay = 13;
    for(int i = 0 ; i<48 ; i++){
        cout<<"---";
        cout.flush();
        Sleep(delay);
    }
}

// Basic Intro to Select Sci. or Simple Cal
void intro(char ch){
    if(tolower(ch) == 's'){
        cout<<endl;
        delayStyle();
        cout<<setw(84)<<"Scientific Calculator"<<endl;
        delayStyle();
    }else{
        cout<<endl;
        delayStyle();
        cout<<setw(80)<<"Simple Calculator"<<endl;
        delayStyle();
    }
}

// Start Simple Cal.
void simpleCal(){
    Calculator simCal;
    char ch ;
    cout<<setw(5)<<"+ : Add"<<endl
        <<setw(5)<<"- : Sub"<<endl
        <<setw(5)<<"* : Multiply"<<endl
        <<setw(5)<<"/ : Divide"<<endl
        <<setw(5)<<"q : quit"<<endl;
    cout<<setw(5)<<"Select the  Operation you want to perform "<<endl;
    while(1){
        cout<<setw(1)<<"-> ";
        cin>>ch;
        if(ch == '+'){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = 0;
            for(int i: nums){
                ans = simCal.add(ans , i);
            }
            cout<<"Result : "<<ans;
            break;
        }else if (ch == '-'){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = nums[0];
            for(int i = 1; i<nums.size() ; i++){
                ans = simCal.sub(ans , nums[i]);
            }
            cout<<"Result : "<<ans ;
            break;
        }else if (ch == '*'){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = 1;
            for(int i: nums){
                ans = simCal.mul(ans , i);
            }
            cout<<"Result : "<<ans<<endl;
            break;
        }else if (ch == '/'){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = nums[0];
            for(int i = 1; i<nums.size() ; i++){
                if(nums[i] == 0){
                    cout<<"Try to Divide by Zero "<<endl;
                    return;
                }
                ans = simCal.div(ans , nums[i]);
            }
            cout<<"Result : "<<ans<<endl;
            break;
        }else if (ch == 'q'){
            delayStyle();
            cout<<setw(78)<<"Calculator OFF"<<endl;
            delayStyle();
            break;
        }else{
            cout<<setw(5)<<"You enter the invalid input , Enter Agian "<<endl;
        }
    }
}

// Start Scitific Cal.
void sciCal(){
    SciCal sciCal;
    string ch;
    cout<<setw(5)<<"+ : Add"<<setw(30)<<"sin : Sin()"<<setw(30)<<"asin : Sin-1()"<<setw(30)<<"log : (log base n)"<<endl
    <<setw(5)<<"- : Sub"<<setw(30)<<"cos : Cos()"<<setw(30)<<"acos : Cos-1()"<<setw(33)<<"log10 : (log base 10)"<<endl
    <<setw(5)<<"* : Multiply"<<setw(25)<<"tan : Tan()"<<setw(30)<<"atan : Tan-1()"<<setw(20)<<"q : quit"<<endl
    <<setw(5)<<"/ : Divide"<<setw(35)<<" sqrt : Square root "<<setw(19)<<"pow : Power"<<endl;

    cout<<setw(5)<<"Select the operation who want to perform"<<endl;

    while(1){
        cout<<setw(1)<<"-> ";
        cin>>ch;
        if(ch == "+"){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = 0;
            for(int i: nums){
                ans = sciCal.add(ans , i);
            }
            cout<<"Result : "<<ans;
            break;
        }else if (ch == "-"){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = nums[0];
            for(int i = 1; i<nums.size() ; i++){
                ans = sciCal.sub(ans , nums[i]);
            }
            cout<<"Result : "<<ans ;
            break;
        }else if (ch == "*"){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = 1;
            for(int i: nums){
                ans = sciCal.mul(ans , i);
            }
            cout<<"Result : "<<ans<<endl;
            break;
        }else if (ch == "/"){
            vector<double> nums = getIn();
            if (nums.size() == 0) {
                cout << "No numbers entered!" << endl;
                return;
            }
            auto ans = nums[0];
            for(int i = 1; i<nums.size() ; i++){
                if(nums[i] == 0){
                    cout<<"Try to Divide by Zero "<<endl;
                    return;
                }
                ans = sciCal.div(ans , nums[i]);
            }
            cout<<"Result : "<<ans<<endl;
            break;
        }else if (ch == "sin"){
            double d;
            cout<<"Enter the degree"<<endl;
            cin>>d;
            cout<<"Result : "<<sciCal.sinR(d)<<endl;
                break;
        }else if (ch == "cos"){
            double d;
            cout<<"Enter the degree"<<endl;
            cin>>d;
            cout<<"Result : "<<sciCal.cosR(d)<<endl;
            break;
        }else if (ch == "tan"){
            double d;
            cout<<"Enter the degree"<<endl;
            cin>>d;
            cout<<"Result : "<<sciCal.tanR(d)<<endl;
            break;
        }else if (ch == "asin"){
            double d;
            repeat:
            cout<<"Enter the value (-1 to 1)"<<endl;
            cin>>d;
            if(d > 1 || d < -1){
                cout<<"You Enter a invalid value , Enter Agian ";
                goto repeat;
            }
            cout<<"Result : "<<sciCal.aSinR(d)<<endl;
                break;
        }else if (ch == "acos"){
            double d;
            repeat2:
            cout<<"Enter the value (-1 to 1)"<<endl<<endl;
            cin>>d;
            if(d > 1 || d < -1){
                cout<<"You Enter a invalid value , Enter Agian ";
                goto repeat2;
            }
            cout<<"Result : "<<sciCal.aCosR(d)<<endl;
                break;
        }else if (ch == "atan"){
            double d;
            cout<<"Enter the value"<<endl;
            cin>>d;
            cout<<"Result : "<<sciCal.atanR(d)<<endl;
                break;
        }else if (ch == "sqrt"){
            double d;
            while(1){
            cout<<"Enter the value"<<endl;
            cin>>d;
            if(d <  0){
                cout<<"You enter a negative number , Enter Again"<<endl;
            }else{
                cout<<"Result : "<<sciCal.root(d)<<endl;
                break;
            }
            }
                break;
        }else if (ch == "pow"){
            double base , exp;
            cout<<"Enter the base "<<endl;
            cin>>base;
            cout<<"Enter the exponent"<<endl;
            cin>>exp;
            cout<<"Result : "<<sciCal.power(base , exp)<<endl;   
            break;     
        }else if (ch == "log"){
            double d;
            cout<<"Enter the value (bigger then 0)"<<endl;
            cin>>d;
            cout<<"Result : "<<sciCal.logBaseN(d)<<endl;
            break;
        }else if (ch == "log10"){
            double d;
            cout<<"Enter the value (bigger than 0)"<<endl;
            cin>>d;
            cout<<"Result : "<<sciCal.logBase10(d)<<endl;
            break;
        }else if (ch == "q"){
            delayStyle();
            cout<<setw(78)<<"Calculator OFF"<<endl;
            delayStyle();
            break;
        }else{
            cout<<setw(5)<<"You enter the invalid input , Enter Agian "<<endl;
        }
}
}

// get Args Input 
vector<double> getIn(){
    vector<double> numbers ;
    string input;
    cout<<"Enter number one by one (type '=' to finish):"<<endl;
    while(1){
        cin>>input;
        if(input == "="){
            break;
        }

        try{
            int num = stod(input);
            numbers.push_back(num);
        } catch(exception &e){
            cout<<"Invalid Input . Please Enter again or '=' ."<<endl;
        }
    }
    return numbers;
}
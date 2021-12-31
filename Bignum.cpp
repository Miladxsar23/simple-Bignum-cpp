#include <iostream>
using namespace std;


struct Big {
        string s;
        /* '=' operation */
        void operator = (int i) {
                while( i > 0 ) {
                        char ch = (i % 10) + '0';
                        s = ch + s;
                        i /= 10;
                }
        }
        /* '+=' operation*/
        void operator += (Big y) {
                string a = s;
                string b = y.s;
                if(a.size() < b.size())
                        swap(a, b);
                while(b.size() < a.size())
                        b = '0' + b;
                int d = 0;
                string sum = "";
                for(int i = b.size() - 1; i >= 0; i--){
                        d = ( a[i] - '0') + (b[i] - '0') + d;
                        char ch = (d % 10) + '0';
                        sum = ch + sum;
                        d /= 10;
                }
                if(d > 0){
                        char ch = (d % 10) + '0';
                        sum = ch + sum;
                }
                s = sum;
        }
        /*multiplication operator*/
        void operator *= (Big y) {
                string a = s;
                string b = y.s;
                if(a.size() > b.size())
                        swap(a, b);
                int d = 0;
                string sum = "";
                Big res, step;
                for(int i = a.size() - 1; i >= 0; i--) {
                        step.s = "";
                        if(i < a.size() - 1){
                                for(int turn = 0; turn < (a.size() - 1) - i; turn++)
                                        step.s += "0";
                        }
                        for(int j = b.size() - 1; j >= 0; j--) {
                                d = (a[i] - '0') * (b[j] - '0') + d;
                                char ch = (d % 10) + '0';
                                step.s = ch + step.s;
                                d /= 10;
                        }
                        if(d > 0) {
                                char ch = (d % 10) + '0';
                                step.s = ch + step.s;
                                d = 0;
                        }
                        res += step;
                }
                s = res.s;
        }
        /*multiplication -> (int) input*/
        void operator *= (int y) {
                Big z;
                z = y;
                *this *= z;
        }
        /*mines operator*/
        void operator -= (Big y) {
                string a = s;
                string b = y.s;
                if(a.size() < b.size())
                        swap(a, b);
                while(b.size() < a.size())
                        b = '0' + b;
                int d = 0;
                string result;
                for(int i = a.size() - 1; i >= 0; i--) {
                        a[i] = (a[i] - '0' - d) + '0';
                        d = 0;
                        if(a[i] < b[i]) {
                                a[i] = ((a[i] - '0') + 10) + '0';
                                d = 1;
                        }
                        char ch = (a[i] - '0') - (b[i] - '0') + '0';
                        result = ch + result;

                }
                s = result;

        }
        /* size method -> return (int)*/
        int size() {
                return s.size();
        }
};


int main () {
        //test
        Big x, y;
        x = 444;
        y = 348;
        x -= y;
        x *= y;
        x += y;
        cout << x.s << endl;
        /* return 33756*/
        return 0;
}

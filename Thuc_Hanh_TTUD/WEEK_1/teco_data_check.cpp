#include <bits/stdc++.h>
using namespace std;

int time_start = 0;
int time_end = 0;
// Hàm check số điện thoại
bool isNumericString(const string &str) {
    // Kiểm tra độ dài chuỗi
    if (str.length() != 10) {
        return false;
    }
    // Kiểm tra từng ký tự trong chuỗi
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}


// hàm chuyển time sang giây
int timeToSeconds(const string& timeStr) {
    int hours, minutes, seconds;
    char colon;
    istringstream iss(timeStr);
    iss >> hours >> colon >> minutes >> colon >> seconds;
    return hours * 3600 + minutes * 60 + seconds;
}

int main()
{
    vector<string> list;
    vector<int> result;
    string temp, input, input2;
    int k, count = 0;

    cin.ignore(0,'\n');
    while(1){
        getline(cin, temp);
        if(temp != "#")  list.push_back(temp);
        else break;
    }


    cin.ignore(0,'\n');
    while(1){
        getline(cin, input);
        if(input != "#"){
        istringstream split(input);
          split >> input;
        if(input == "?check_phone_number"){
               for(int i = 0; i < list.size(); i++){
                  istringstream split(list[i]);
                //   split >> list[i];
                  split >> input2;
                  //   split >> list[i];
                  split >> input2;


                if(!isNumericString(input2)){
                     k = 0;
                     break;
                }else {
                    k = 1;

                }
            }
            if(k == 1){
                result.push_back(1);
            }
        }else if(input == "?number_calls_from"){
            split >> input;
            for(int i = 0; i < list.size(); i++){
                  istringstream split(list[i]);
                  //   split >> list[i];
                  split >> input2;
                  //   split >> list[i];
                  split >> input2;
                  // if(input == list[i]){
                if(input == input2){
                     count++;
                }
            }
            result.push_back(count);
            count = 0;

        }else if(input == "?number_total_calls"){
            result.push_back(list.size());
        }else if(input == "?count_time_calls_from"){
            int total_time = 0;
            split >> input;
            for(int i = 0; i < list.size(); i++){
                 istringstream split(list[i]);
                  //split >> list[i];

                  //split >> list[i];

                split >> input2;
                split >> input2;
                // if(input == list[i]){
                if(input == input2){

                      split >> input2;
                    //   split >> list[i];
                    //   cout << input2 << endl;
                      split >> input2;
                    //   split >> list[i];
                    //   cout << input2 << endl;
                      split >> input2;
                    //   split >> list[i];
                    //   cout << input2 << endl;
                      time_start = timeToSeconds(input2);
                      split >> input2;
                       time_end = timeToSeconds(input2);
                    //   cout << time_start << ' ' << time_end << endl;
                      total_time += time_end - time_start;
                    // cout << time_start << ' ' << time_end << " " << total_time << endl;
                }
            }

            result.push_back(total_time);
            total_time = 0;
            time_end = 0;
            time_start = 0;


        }
        else{
            break;
        }
    }else break;
}


 for(int i = 0; i < result.size(); i++){
     cout<< result[i] << endl;
 }
}

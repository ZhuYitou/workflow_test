#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MaxSize = 20;

template<class T>
class MyCards {
public:
    MyCards(T *a, int size); //构造函数，传入初始手牌数组

    void Match();// 弃置配对牌操作
    void Show();  //展示手牌操作

private:
    T cards[MaxSize] = {};
    int card_num = 0;

    T ans[MaxSize] = {};
    int ans_num = 0;
};

template<class T>
MyCards<T>::MyCards(T *a, int size) {
    card_num = size;
    for (int i = 0; i < card_num; ++i) {
        cards[i] = a[i];
    }
}

template<class T>
void MyCards<T>::Match() {
    sort(cards, cards + card_num);

//    for (int i = card_num - 1; i > 0; --i) {
//        cout << cards[i] << ' ';
//    }
//    cout << cards[0];

    bool is_ans = true;
    for (int i = 1; i < card_num; ++i) {
        if (cards[i] == cards[i - 1]) {
            is_ans = !is_ans;
        } else {
            if (is_ans) {
                ans[ans_num] = cards[i - 1];
                ans_num++;
            }
            is_ans = true;
        }
    }

    if (is_ans) {
        ans[ans_num] = cards[card_num - 1];
        ans_num++;
    }
}

template<class T>
void MyCards<T>::Show() {
    cout<<ans_num<<endl;
    if(ans_num!=0) {
        for (int i = ans_num - 1; i > 0; --i) {
            cout << ans[i] << ' ';
        }
        cout << ans[0];
    }else{
        cout<<"WIN";
    }
}

int main() {
    int kind = 0;
    cin >> kind;

    int num[MaxSize] = {};
    char letter[MaxSize] = {};

    cin.clear();
    cin.ignore();

    string input;
    getline(cin, input);
    int input_num =0;

    if (kind == 1) {//1-13
        int index =0;
        while(index<(int) input.length()) {
            if(input[index]!=' ') {
                num[input_num] = num[input_num] * 10 + ((unsigned char) input[index] - '0');
            }else{
                input_num++;
            }
            index++;
        }
        input_num++;

//        for (int i = 0; i < input_num; ++i) {
//            cout << num[i] << ' ';
//        }
//        cout<<endl;

        MyCards<int> myCards(num, input_num);
        myCards.Match();
        myCards.Show();
    } else {//A-M
        input_num = ((int) input.length() + 1) / 2;

        for (int i = 0; i < input_num; ++i) {
            letter[i] = input[i * 2];
        }
        MyCards<char> myCards(letter, input_num);
        myCards.Match();
        myCards.Show();
    }

    return 0;
}

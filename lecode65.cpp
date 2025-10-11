// 状态机
#include <string>
using namespace std;
enum class State : int{
    START,
    SIGN,
    DIGIT,
    DOT,
    DEC,
    DIGIT_DOT,
    E,
    E_SIGN,
    E_DIGIT,
    INVAILD
};
enum class Event : int{
    SIGN,
    DIGIT,
    DOT,
    E,
    OTHER
};

 
Event GetEvent(char ch){
    if(ch == '-' || ch == '+') return Event::SIGN;
    if(isdigit(ch)) return Event::DIGIT;
    if(ch == '.') return Event::DOT;
    if(ch == 'e' || ch == 'E') return Event::E;
    return Event::OTHER;
}


class Solution {
    public:


    // SIGN,
    // DIGIT,
    // DOT,
    // E,
    // OTHER
        State table[static_cast<int>(State::INVAILD) + 1][static_cast<int>(Event::OTHER) + 1] = {
                {State::SIGN,State::DIGIT,State::DOT,State::INVAILD,State::INVAILD},// START
                {State::INVAILD,State::DIGIT,State::DOT,State::INVAILD,State::INVAILD},// SIGN
                {State::INVAILD,State::DIGIT,State::DEC,State::E,State::INVAILD},// DIGIT
                {State::INVAILD,State::DEC,State::INVAILD,State::INVAILD,State::INVAILD},// DOT
                {State::INVAILD,State::DEC,State::INVAILD,State::E,State::INVAILD},// DEC
                {State::INVAILD,State::DEC,State::INVAILD,State::E,State::INVAILD},// DIGIT_DOT
                {State::E_SIGN,State::E_DIGIT,State::INVAILD,State::INVAILD,State::INVAILD},// E
                {State::INVAILD,State::E_DIGIT,State::INVAILD,State::INVAILD,State::INVAILD},// E_SIGN
                {State::INVAILD,State::E_DIGIT,State::INVAILD,State::INVAILD,State::INVAILD},// E_DIGIT
                {State::INVAILD,State::INVAILD,State::INVAILD,State::INVAILD,State::INVAILD} // INVAILD
            };
        bool isNumber(string s) {
            State current = State::START;
            for(char temp : s) {
            current = table[static_cast<int>(current)][static_cast<int>(GetEvent(temp))];
            if(current == State::INVAILD) break;
        }

            return current == State::DIGIT ||
            current == State::DEC ||
            current == State::DIGIT_DOT ||
            current == State::E_DIGIT;
        }
    };
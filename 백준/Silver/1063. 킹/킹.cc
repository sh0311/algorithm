#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <cmath>

using namespace std;

//c++에서 참조(&)을 이용해 인자로 전달하면 함수내에서 일어난게 함수 외부에도 반영된다
void move(string order, char& kingChar, char& stoneChar, int& kingInt, int& stoneInt) {
    int dx = 0, dy = 0;

    if (order.find('R') != string::npos)
        dx = 1;
    if (order.find('L') != string::npos)
        dx = -1;
    if (order.find('B') != string::npos)
        dy = -1;
    if (order.find('T') != string::npos)
        dy = +1;

    char newKingChar = kingChar + dx;
    int newKingInt = kingInt + dy;

    //체스판 벗어나는지
    if (newKingChar < 'A' || newKingChar > 'H' || newKingInt < 1 || newKingInt > 8) {
        return;
    }
    //돌이랑 겹치는지{
    if (newKingChar == stoneChar && newKingInt == stoneInt) {
        char newStoneChar = stoneChar + dx;
        int newStoneInt = stoneInt + dy;
        if (newStoneChar < 'A' || newStoneChar > 'H' || newStoneInt < 1 || newStoneInt > 8) {
            return;
        }
        stoneChar = newStoneChar;
        stoneInt = newStoneInt;
    }
    kingChar = newKingChar;
    kingInt = newKingInt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char kingChar, stoneChar;
    int kingInt, stoneInt, num;

    cin>>kingChar>>kingInt;
    cin>>stoneChar>>stoneInt;

    cin>>num;

    string order;

    for(int i=0;i<num;i++){
        cin>>order;
        move(order, kingChar, stoneChar, kingInt, stoneInt);
    }

    cout<<kingChar<<kingInt<<'\n'<<stoneChar<<stoneInt;

}
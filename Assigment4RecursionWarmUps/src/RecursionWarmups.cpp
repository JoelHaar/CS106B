// This is the .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "gwindow.h"
#include "simpio.h"
#include "math.h"
using namespace std;

int CountPaths(int street, int avenue)
{
        //cout << "(" << street << "," << avenue << ")" << endl;

        if(street == 1 || avenue == 1)
                return 1;
        else
        {
               return CountPaths(street-1,avenue) + CountPaths(street,avenue-1);
        }
}

bool isBalanced(string exp) {
    cout << exp.size() / 2 << endl;
    string newEXP = exp.substr((exp.size() / 2 - 1),2);
    cout << newEXP << endl;
    cout << exp.size() / 2 << endl;

    cout << exp << endl;
      if (exp == "")
        return true;
      if (newEXP == "()" || newEXP == "[]" || newEXP == "{}") {
          exp.erase(exp.size() / 2 - 1,(exp.size() / 2));

                isBalanced(exp);
        }

    else
    return false;

}
void drawTriangles(GWindow& gw, double x, double y, double size, int order,double height) {


            gw.drawLine(x,y,x+size,y);
            gw.drawLine(x,y,x+size/2,y+height);
            gw.drawLine(x+size,y,x+size-size/2,y+height);

    }


void drawSierpinskiTriangle(GWindow& gw, double x, double y, double size, int order) {
    // TODO: write this function
    const double SIZE = 520;
    if (order == 0) return;


    int height = sqrt (size*size - (size / 2) * (size / 2));

    drawTriangles(gw, x, y, size,order,height);

    drawSierpinskiTriangle(gw,x,y,size/2,order - 1);
    drawSierpinskiTriangle(gw,x+size/2, y,size/2,order - 1);
    drawSierpinskiTriangle(gw,x + size / 4, y+height/2,size/2,order - 1);

}

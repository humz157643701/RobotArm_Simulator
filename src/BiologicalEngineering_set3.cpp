/*------------------------------------------------------*/
/* Biological Engineering: Problem Set 03               */
/* main program                                         */
/*                                                      */
/* file name    :   BiologicalEngineering_set3.cpp      */
/* compiler     :   gcc                                 */
/* Student ID   :   1526084                             */
/* author       :   Takaharu Nakajima                   */
/* date         :   2016.11.11                          */
/* memo         :   $B@8BN9)3XBh;02sL\$N(B1.1$B$+$i(B1.3$B$N(B      */
/*                  $B%W%m%0%i%`$r$^$H$a$?$b$N$K$J$j$^$9(B  */
/*                                                      */
/*                  $B0lItJQ?t$NDj5A$N$?$aJQ99$7$?ItJ,(B    */
/*                  ($BNc(B)                                */
/*                  RT0 -> RTa                          */
/*                  $B$3$N$h$&$K(B0, 1...E$B$r(Ba, b...E$B$K(B      */
/*                  $BJQ99$7$^$7$?(B                        */
/*                                                      */
/*------------------------------------------------------*/

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#define PI 3.1415926

double deg2rad(double degree)
{
    double radian = degree * PI / 180.0f;
    return radian;
}

int main()
{
    double deg1, deg2, deg3;
    double rad1, rad2, rad3;
    Matrix<double,4,4> RTa, aTb, bTc, cTe, eTE;
    Matrix<double,4,4> RTb, RTc, RTe, RTE;
    Vector3d RZa, RZb, RZc, RZe, RZE;
    Vector3d Rpa, Rpb, Rpc, Rpe, RpE;
    Vector3d RpEa, RpEb, RpEc, RpEe, RpEE;

    /* Input */
    cout << "Angle input" << endl;
    cout << "deg1= ";
    cin >> deg1;
    cout << "deg2= ";
    cin >> deg2;
    cout << "deg3= ";
    cin >> deg3;

    /* Convert to radians */
    rad1 = deg2rad(deg1);
    rad2 = deg2rad(deg2);
    rad3 = deg2rad(deg3);

    /* Link parameters */
    RTa << 1, 0, 0, 0,
           0, 1, 0, 0, 
           0, 0, 1, 2, 
           0, 0, 0, 1;
    aTb << cos(rad1), -sin(rad1), 0, 0,
           sin(rad1),  cos(rad1), 0, 0,
                   0,          0, 1, 0,
                   0,          0, 0, 1;
    bTc << cos(rad2), -sin(rad2), 0, 0,
                   0,          0, -1, 0,
           sin(rad2),  cos(rad2), 0, 0, 
                   0,          0, 0, 1;
    cTe << cos(rad3), -sin(rad3), 0, 2,
           sin(rad3),  cos(rad3), 0, 0, 
                   0,          0, 1, 0, 
                   0,          0, 0, 1;
    eTE << 1, 0, 0, 2, 
           0, 1, 0, 0, 
           0, 0, 1, 0, 
           0, 0, 0, 1; 

    /* Matrix calculation */
    RTb = RTa * aTb;
    RTc = RTb * bTc;
    RTe = RTc * cTe;
    RTE = RTe * eTE;

    RZa = RTa.block<3,1>(0,2);
    RZb = RTb.block<3,1>(0,2);
    RZc = RTc.block<3,1>(0,2);
    RZe = RTe.block<3,1>(0,2);
    RZE = RTE.block<3,1>(0,2);

    Rpa = RTa.block<3,1>(0,3);
    Rpb = RTb.block<3,1>(0,3);
    Rpc = RTc.block<3,1>(0,3);
    Rpe = RTe.block<3,1>(0,3);
    RpE = RTE.block<3,1>(0,3);

    RpEa = RpE - Rpa;
    RpEb = RpE - Rpb;
    RpEc = RpE - Rpc;
    RpEe = RpE - Rpe;
    RpEE = RpE - RpE;
    
    /* Calculation result display */
    /* RT0 ~ 3TE */
    cout << "RT0=" << endl;
    cout << RTa << endl;
    cout << "0T1=" << endl;
    cout << aTb << endl;
    cout << "1T2=" << endl;
    cout << bTc << endl;
    cout << "2T3=" << endl;
    cout << cTe << endl;
    cout << "3TE=" << endl;
    cout << eTE << endl << endl;

    /* RZ0 ~ RZE */
    cout << "RZ0=" << endl;
    cout << RZa << endl;
    cout << "RZ1=" << endl;
    cout << RZb << endl;
    cout << "RZ2=" << endl;
    cout << RZc << endl;
    cout << "RZ3=" << endl;
    cout << RZe << endl;
    cout << "RZE=" << endl;
    cout << RZE << endl;

    /* Rp0 ~ Rp1 */
    cout << "Rp0=" << endl;
    cout << Rpa << endl;
    cout << "Rp1=" << endl;
    cout << Rpb << endl;
    cout << "Rp2=" << endl;
    cout << Rpc << endl;
    cout << "Rp3=" << endl;
    cout << Rpe << endl;
    cout << "RpE=" << endl;
    cout << RpE << endl;

    /* RZ0 x RpE,0 ~ RZE x RpE,E */
    cout << "RZ0 x RpE,0=" << endl;
    cout << RZa.cross(RpEa) << endl;
    cout << "RZ1 x RpE,1=" << endl;
    cout << RZb.cross(RpEb) << endl;
    cout << "RZ2 x RpE,2=" << endl;
    cout << RZc.cross(RpEc) << endl;
    cout << "RZ3 x RpE,3=" << endl;
    cout << RZe.cross(RpEe) << endl;
    cout << "RZE x RpE,E=" << endl;
    cout << RZE.cross(RpEE) << endl;

    return 0;
}

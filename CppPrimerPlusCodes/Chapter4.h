#ifndef __CHAPTER4_H__
#define __CHAPTER4_H__

const short NameSize = 40;

//  e5
struct CandyBar {
    //string	candyBrand;			// an error will be reported on vc6.0 when snack was initialzing using "string" type.
    char	candyBrand[40];
    int		candyCalorie;
    double	candyWeight;
};

void Exercise04_01();
void Exercise04_02();
void Exercise04_03();
void Exercise04_04();
void Exercise04_05();
void Exercise04_06();
void Exercise04_07();
void Exercise04_08();
void Exercise04_09();

#endif
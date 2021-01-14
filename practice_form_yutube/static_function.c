#include<stdio.h> 
#include<math.h>

// Learn static varaible
void demo(){ 
    int n = 1;
    static int sv = 1; // ตัวมันเองจะมี lift time เท่ากับตัว main
    printf(" n = %d, sv = %d\n", n, sv);
    n++;   // 
    sv++; // จดจำค่าเดิมได้ 

}
void move(int x, int y){
    static int prevx = 0;
    static int prevy = 0;
    double distance = sqrt(pow(prevx - x, 2) +  pow(prevy - y, 2));
    printf("distance((%d, %d), (%d, %d)0 = %.2f\n", prevx, prevy, x, y, distance);
    prevx = x;
    prevy = y;

}

// Learn structure
//struct sctruc_nam { 
//  struc_var; 
struct Coord {
    double x;
    double y;
};
double distance2(struct Coord p1,struct Coord p2) {
    struct Coord p3;
    // การเรียกใช้ : struc_name struct_varname
    // เป็นการระบุว่า p1 มีตัวแปรข้างในสองตัว คือ x, y (varname p1 have 2 data is x y)
    // เป็นการระบุว่า p2 มีตัวแปรข้างในสองตัว คือ x, y (varname p2 have 2 data is x y)
    // return double
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
};
double distance1(double x1, double y1, double x2, double y2) { 
    return sqrt(pow((x1- x2), 2) + pow((y1 - y2), 2));
}
 
// Learn many return -> have a pointer 
    // TOTAL price = 107, price = 100, VAT = 7 
void pricePart( double totalPrice, double *price, double *vat) { // function เป็น void 
    *vat = totalPrice * 7.0 / 107;
    *price = totalPrice - *vat;
}

typedef struct Pricetype{ 
    double price;
    double vat; 
} Pricetype;
Pricetype pricePart2(double totalPrice) { 
    Pricetype p; // ภือเะป็นการส่งกลับมา ค่าเดียว datatype : Pricetype
    p.vat = totalPrice * 7.0 / 107;
    p.price = totalPrice - p.vat;
    return p; 
}

int main () { 
    // static variable
    printf("==================LEARN STATIC VARIABLE===================\n");
    for(int i = 0; i < 5; i++) { 
        // demo();
        move(i + 5, i *2);
    }

    // structure 
    printf("==================LEARN STRUCK============================\n");
    // diatance 1 nomal step 
    double d1 = distance1(2, 5, 4, 10);
    printf("normal way   -> d1 = %.2f\n", d1);

    // distance 2 struct keywordy (assign ่า)
    struct Coord p1; // เรียกใช้ แบบยาว ต้องเรียกใช้ก่อน ค่อย assign ค่า 
    p1.x = 2; // assign object_name p1 ที่เป็น struct 
    p1.y = 5; // assign object_name p2 ที่เป็น struct 
    struct Coord p2 = {4, 10}; // เรียกใช้ แบบสั้น ต้องเรียกใช้ก่อน ค่อย assign ค่า 
    double d2 = distance2(p1, p2);
    printf("structur way -> d2 = %.2f\n", d2);

    // 
    printf("==================LEARN MANY WRETUEN======================\n");
    double totalPrice, price, vat; 
    totalPrice = 107;
    pricePart(totalPrice, &price, &vat);
    printf("total price = %.2f, price = %.2f, vat = %.2f\n", totalPrice, price, vat);

    Pricetype p_main = pricePart2(totalPrice); 
    printf("total price = %.2f, price = %.2f, vat = %.2f\n", totalPrice, p_main.price, p_main.vat);

}
#include <stdio.h>
int main()
{
    double h, w, d, tolsina1, tolsina2, tolsina3, polka, DVP, DSP, wood, V1, m1, V2, m2, V3, m3, V4, m4, V5, m5;
    tolsina1 = 0.5;
    tolsina2 = 0.15;
    tolsina3 = 1;
    polka = 40;
    DVP = 0.95;
    DSP = 0.75;
    wood = 0.6;
    int k = 0;
    int t = 0;
    printf("Input h,w,d: ");
    do{
        t = 0;
        scanf("%lf %lf %lf", &h, &w, &d);
        if((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90)){
            t = 1;
        }
    }while(t);
    V1 = h * w * tolsina1;//накладна€ задн€€ степна
    m1 = DVP * V1;
    V2 = 2 * (h * d * tolsina2);//2 боковины
    m2 = V2 * DSP;
    V3 = 2 * (w * d * tolsina2);//верхн€€ и нижн€€ крышки
    m3 = V3 * DSP;
    V4 = h * w * tolsina3;//накладные двери
    m4 = V4 * wood;
    V5 = w * d * tolsina2;//одна полка
    m5 = DSP * V5;
    while (h >= 40) {
        k++;
        h -= 40;
    }
    m5 *= k;
    printf("Weight:%lf\n", (m1 + m2 + m3 + m4 + m5)/1000);
}

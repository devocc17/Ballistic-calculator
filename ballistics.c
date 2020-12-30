// calculate ballistics
// going off a 100 yard zero

#include <stdio.h>
#include <math.h>

float bulletdrop(int h, int vol);
float impact(int h);
float flighttime(int h);
float mils(int target);

int main(void){

	// for distance
        int d, m;
        char input;
        // calaber size
        char cal;
        int v;

        // bulet drop, wind speed/drift, elevation
        int drop, elv, imp;
        float wind, time;

        // mills
        char scope, junk;
        int mil, size;
        printf("Hello, Welcome to Devin's Balllistic calculator. \n");

        printf("Enter gun Calaber: (1. .22) (2. 30-06) (3. .223) (4. .308) (5. .556) (6. 8mm Mauser): ");
                scanf("%c%c", &cal, &junk);


        switch(cal){
                case '1':
                        printf(".22");
                        v = 1750;
                break;
                case '2':
                        printf("30-06");
                        v = 3080;
                break;
                case '3':
                        printf(".223");
                        v = 4000;
                break;
                case '4':
                        printf(".308");
                        v = 2800;
                break;
                case '5':
                        printf(".556");
                        v = 3130;
                break;
                case '6':
                        printf("8x57mm Mauser");
                        v = 26500;
                break;

        }
        printf("\n");
        printf("Start at the highest magnification on scope\n");

        printf("Do you know the distance?: ");
          scanf("%c%c", &input, &junk);
        if(input == 'y'){

          printf("Enter Distance:");
                scanf("%d%c", &d, &junk);
          drop = bulletdrop(d, v);
         printf("Your dope is: %d \n", drop);

        imp = impact(d);
        printf("Your impact volocity is: %d\n", imp);

        time = flighttime(d);
        printf("Your time of flight is: %f\n", time);

      }else if(input == 'n'){

      /*    printf("Does the rifle have a MIL-dot scope:");
                  scanf("%c%c", &scope, &junk);*/

          printf("How many MIL's is the target: ");
            scanf("%d", &mil);
          size = mils(mil);
          printf("The target is %d\n", size);
         drop = bulletdrop(size, v);
        printf("Your dope is: %d \n", drop);

        imp = impact(size);
        printf("Your impact volocity is: %d\n", imp);

        time = flighttime(size);
        printf("Your time of flight is: %f\n", time);
      }

                  if(d == 100){
                        printf("1 click = 0.36 inches at 100 yards\n");
                        return 1;
                  }else if(d == 200){
                        printf("1 click = 7.2 inches at 200 yards\n");
                        return 1;
                  }else if(d == 300){
                        printf("1 click = 10.8 inches at 300 yards\n");
                        return 1;
                  }else if(d == 400){
                        printf("1 click = 14.4 inches at 400 yards\n");
                        return 1;
                  }else if(d == 500){
                        printf("1 click = 18.0 inches at 500 yards\n");
                        return 1;
                  }else if(d == 600){
                        printf("1 click = 21.6 inches at 600 yards\n");
                        return 1;
                  }

return 0;
}
float bulletdrop(int h, int vol){

        //h is the range/distance user inputs

        float g = 9.8;

        return vol * (sqrt(2 * h / g));
}
float impact(int h){

        float g = 9.8;

        return sqrt(2 * g * h);
}
float flighttime(int h){

        float g = 9.8;

        return sqrt(2 * h / g);
}
float mils(int target){
  
  return (target * 1000)/4;
}

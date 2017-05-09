#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int i;
    FILE *fdx, *fdy, *fdz;
    float scale, xval, yval, zval;

    printf("Hello world!\n");

    // Read scale value
    fdx = fopen("/sys/bus/iio/devices/iio:device1/in_accel_scale", "r");
    fscanf(fdx, "%f", &scale);
    printf("Scale is: %f\n", scale);
    fclose(fdx);
 
    // Read accel-x value 5 times
    for(i = 0; i < 5; i++){
        // Open files
        fdx = fopen("/sys/bus/iio/devices/iio:device1/in_accel_x_raw", "r");
        fdy = fopen("/sys/bus/iio/devices/iio:device1/in_accel_y_raw", "r");
        fdz = fopen("/sys/bus/iio/devices/iio:device1/in_accel_z_raw", "r");
        
        // Read files
        fscanf(fdx, "%f", &xval);
        fscanf(fdy, "%f", &yval);
        fscanf(fdz, "%f", &zval);

        // Print the accel values and wait 1 second
        printf("Run %d:\n", i);
        printf("X accel: %f - Y accel: %f - Z accel: %f\n", (scale*xval), (scale*yval), (scale*zval));
        usleep(1000000);

        // Close files
        fclose(fdx);
        fclose(fdy);
        fclose(fdz);
    }

    return EXIT_SUCCESS;
}

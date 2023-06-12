#include "../include/SorterDic.h"

// A utility function to swap two points
void swap(Point& p1, Point& p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int compare(const void *vp1, const void *vp2){
    return 0;
}

void graham(Point points[], int size, Sorters sort){

    // Acha o ponto com Y mais baixo
    int ymin = points[0].getY(), min = 0;
    for (int i = 1; i < size; i++) {
        int y = points[i].getY();
 
        if ((y < ymin) || (ymin == y && points[i].getX() < points[min].getX()))
            ymin = points[i].getY(), min = i;
    }
 
    // Coloca esse ponto como 1º
    swap(points[0], points[min]);

    // Ordena os pontos
    if(sort == MERGE){
        mergeSort(points, size);
    } else if(sort == INSERT){
        insertionSort(&points[1], size, points[0]);
    } else if(sort == BUCKET){
        bucketSort(&points[1], size, points[0])
    }


}
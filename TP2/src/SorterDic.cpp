#include "../include/SorterDic.h"

// ===== COMPARE =====

Point p0;

int compare(Point& vp1, Point& vp2)
{
    Point p1 = (Point *) vp1;
    Point p2 = (Point *) vp2;
 
    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
 
    delete p1;
    delete p2;

    return (o == 2) ? -1 : 1;
}


// ===== MERGE =====

void merge(Point points[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Point* leftArray = new Point[n1];
    Point* rightArray = new Point[n2];

    for(int i = 0; i < n1; ++i) {leftArray[i] = points[left + i];}
    for(int i = 0; i < n2; ++i) {rightArray[i] = points[mid + 1 + i];}

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compare(leftArray[i],  rightArray[j])) {
            points[k] = leftArray[i];
            ++i;
        } else {
            points[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        points[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        points[k] = rightArray[j];
        ++j;
        ++k;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSorter(Point points[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(points, left, mid);
    mergeSort(points, mid + 1, right);

    merge(points, left, mid, right);
  }
}

void mergeSort(Point points[], int size) {

    p0 = points[0];
    mergeSorter(points[1], 0, size - 1);
}


// ===== INSERTION =====

void insertionSort(Point points[], int size, Point& pZero) {

    p0 = pZero;

    for (int i = 1; i < size; ++i) {
        Point* key = points[i];
        int j = i - 1;
        
        while (j >= 0 && compare(points[j], key)) {
        points[j + 1] = points[j];
        --j;
        }
        
        points[j + 1] = key;
    }
}


// ===== BUCKET =====

void bucketSort(Point points[], int size, Point& pZero) {
    
    p0 = pZero;
/* 
    // Create empty buckets
    std::vector<std::vector<float>> buckets(n);

    // Put elements into respective buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * points[i];
        buckets[bucketIndex].push_back(points[i]);
    }

    // Sort elements within each bucket
    for (int i = 0; i < n; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (float num : buckets[i]) {
        nums[index++] = num;
        }
    } */
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "node.h"
#include "DEQ2.h"
using namespace std;

double calculateP_arrival(double deltaT) {
    return 1.0 / deltaT;
}

double T_s = 10;
double deltaT = 6;
double P_arrival = calculateP_arrival(deltaT);
int T_arrival;

void Arrival(DEQ2<int>& Q, int t, int& arrivalCounter) {
    float R = rand( ) / float(32767);
    if (R < P_arrival) {
        arrivalCounter++;
        // if we want to check that the Queue is full we will use the commented code
        // if (Q.DEQ_Length() == 10) {
        //     cout << "Arrival#" << arrivalCounter << " at: " << t << " - Line is full" << endl;
        // } else {
           T_arrival = t; 
            cout << "Arrival#" << arrivalCounter << " at: " << T_arrival << endl;
            node<int>* T_arrive = new node<int>(T_arrival);
            Q.Add_Rear(T_arrive);
       // }
    }
}

void ExitLine(DEQ2<int>& Q, int t, int& waitTotal, int& jobcount) {
    if (!Q.DEQisEmpty()) {
        int Planearrival = Q.View_Front();
         int T_wait=0;
        if(t>=Planearrival)
        {
          T_wait= t-Planearrival;
        }
        Q.Remove_Front();
        waitTotal = waitTotal+ T_wait;
        jobcount= jobcount+1;
        cout << "Job#" << jobcount << " Service Started at: " << t << " wait = " << T_wait << endl;
        
    }
}

void Service(DEQ2<int>& Q, int t, double& T_rem, int& waitTotal, int& jobcount) {
    if (T_rem == 0 && !Q.DEQisEmpty()) {
        ExitLine(Q, t, waitTotal, jobcount);
        T_rem = T_s;
    }
}

double AverageWait(int waitTotal, int jobcount) {
    if(jobcount==0)
    {
        return 0;
    }
    else 
    {
        return waitTotal / static_cast<double>(jobcount);
    }

}

int main() {
    srand(time(0));
    double T_max = 6 * 60;
    int t = 0;
    double T_rem = 0;
    int waitTotal = 0;
    int jobcount = 0;
    int arrivalCounter = 0;
    DEQ2<int> Q;

    while (t < T_max) {
        Arrival(Q, t, arrivalCounter);
        Service(Q, t, T_rem, waitTotal, jobcount);

        if (T_rem > 0) {
            T_rem--;
        }
        t++;
    }

    

    double average = AverageWait(waitTotal, jobcount);
    cout << "Average wait Time is " << average << endl;

    return 0;
}

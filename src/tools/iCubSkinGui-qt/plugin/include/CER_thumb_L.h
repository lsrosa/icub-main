// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2019 Istituto Italiano di Tecnologia (IIT)
 *
 * This software may be modified and distributed under the terms of the
 * GPL-2+ license. See the accompanying LICENSE file for details.
 */

/*!
 *  \brief     In here there are the class definitions for proximal and distal thumb of CER(mk2)
 *  \author    Valentina Gaggero
 *  \date      July 2019
 *  \copyright GPL-2+ license
 */

#include "include/TouchSensor.h"

#ifndef __CER_thumb_L_H__
#define __CER_thumb_L_H__

class CER_thumbFlexProximal_L : public TouchSensor
{
public:

    CER_thumbFlexProximal_L(double cx,double cy,double th,double gain=1.0,int layoutNum=0,int lrMirror=0)
    {
        const double DEG2RAD=M_PI/180.0;

        const double CST=cos(DEG2RAD*th);
        const double SNT=sin(DEG2RAD*th);

        dGain=gain;
        ilrMirror=lrMirror;
        ilayoutNum=layoutNum;
        nVerts=5;
        nTaxels=24;
        m_RadiusOrig=1.8;

        for (int i = 0; i<nTaxels; ++i) dX[0] = dY[0] = 0.0;

        int n = 0;

        dX[n]= 0.0;  dY[n++]= 0.0;  //    0
        dX[n]= 5.0;  dY[n++]= 0.0;  //    1
        dX[n]= 5.0;  dY[n++]= 5.0;  //    2
        dX[n]=-5.0;  dY[n++]= 0.0;  //    3
        dX[n]=-10.0; dY[n++]= 0.0;  //    4
        dX[n]= 0.0;  dY[n++]= 5.0;  //    5
        dX[n]=-5.0;  dY[n++]= 5.0;  //    6
        dX[n]=-10.0; dY[n++]= 5.0;  //    7
        dX[n]=-10.0; dY[n++]= 10.0; //    8
        dX[n]=-5.0;  dY[n++]= 10.0; //    9
        dX[n]= 0.0;  dY[n++]= 10.0; //    10

        connected[n++] = false;     //    11 (-2.5, 7.5)

        dX[n]=-5.0;  dY[n++]=-15.0; //    12
        dX[n]=-10.0; dY[n++]=-15.0; //    13
        dX[n]= 5.0;  dY[n++]=-15.0; //    14
        dX[n]=-10.0; dY[n++]=-10.0; //    15
        dX[n]=-5.0;  dY[n++]=-10.0; //    16
        dX[n]= 0.0;  dY[n++]=-15.0; //    17
        dX[n]=-10.0; dY[n++]=-5.0;  //    18
        dX[n]=-5.0;  dY[n++]=-5.0;  //    19
        dX[n]= 0.0;  dY[n++]=-5.0;  //    20
        dX[n]= 0.0;  dY[n++]=-10.0; //    21
        dX[n]= 5.0;  dY[n++]=-5.0;  //    22

        connected[n++] = false;     //    23   (-2.5, -7.5)
        connected[n++] = false;     //    24
        connected[n++] = false;     //    25
        connected[n++] = false;     //    26
        connected[n++] = false;     //    27
        connected[n++] = false;     //    28
        connected[n++] = false;     //    29
        connected[n++] = false;     //    30
        connected[n++] = false;     //    31
        connected[n++] = false;     //    32
        connected[n++] = false;     //    33
        connected[n++] = false;     //    34
        connected[n++] = false;     //    35

        for (int i=0; i<nTaxels; ++i)
        {
            double x=dX[i]-0.0;
            double y=dY[i]-0.0;

            if (lrMirror) x=-x;

            dX[i]=cx+CST*x-SNT*y;
            dY[i]=cy+SNT*x+CST*y;
        }

        dXv[0]=-12.5;  dYv[0]= 12.5;
        dXv[1]=-12.5;  dYv[1]=-17.5;
        dXv[2]= 8.5;  dYv[2]=-17.5;
        dXv[3]= 8.5;  dYv[3]= 7.5;
        dXv[4]= 2.5;  dYv[4]= 12.5;




        for (int i=0; i<nVerts; ++i)
        {
            double x=dXv[i];
            double y=dYv[i];
            if (lrMirror) x=-x;
            dXv[i]=cx+CST*x-SNT*y;
            dYv[i]=cy+SNT*x+CST*y;
        }

        // in static definition
        //dXmin=dYmin= HUGE;
        //dXmax=dYmax=-HUGE;

        for (int i=0; i<nVerts; ++i)
        {
            if (dXv[i]<dXmin) dXmin=dXv[i];
            if (dXv[i]>dXmax) dXmax=dXv[i];
            if (dYv[i]<dYmin) dYmin=dYv[i];
            if (dYv[i]>dYmax) dYmax=dYv[i];
        }

        dXc=cx;
        dYc=cy;
    }
};


class CER_thumbFlexDistal_L : public TouchSensor
{
public:

    CER_thumbFlexDistal_L(double cx,double cy,double th,double gain=1.0,int layoutNum=0,int lrMirror=0)
    {
        const double DEG2RAD=M_PI/180.0;

        const double CST=cos(DEG2RAD*th);
        const double SNT=sin(DEG2RAD*th);

        dGain=gain;
        ilrMirror=lrMirror;
        ilayoutNum=layoutNum;
        nVerts=4;
        nTaxels=36;
        m_RadiusOrig=1.8;

        for (int i = 0; i<nTaxels; ++i) dX[0] = dY[0] = 0.0;

        int n = 0;

        dX[n]= 0.0;  dY[n++]= 0.0;  //    0
        dX[n]=-5.0;  dY[n++]= 0.0;  //    1
        dX[n]= 5.0;  dY[n++]= 0.0;  //    2
        dX[n]=10.0;  dY[n++]= 0.0;  //    3
        dX[n]=15.0;  dY[n++]= 0.0;  //    4
        dX[n]=15.0;  dY[n++]=-5.0;  //    5
        dX[n]=10.0;  dY[n++]=-5.0;  //    6
        dX[n]= 5.0;  dY[n++]=-5.0;  //    7
        dX[n]= 0.0;  dY[n++]=-5.0;  //    8
        dX[n]=15.0;  dY[n++]=-10.0; //    9
        dX[n]=10.0;  dY[n++]=-10.0; //    10

        connected[n++] = false;     //    11

        dX[n]= 0.0;  dY[n++]=-10.0; //    12
        dX[n]=-5.0;  dY[n++]=-10.0; //    13
        dX[n]= 5.0;  dY[n++]=-10.0; //    14
        dX[n]=15.0;  dY[n++]=-15.0; //    15
        dX[n]=10.0;  dY[n++]=-15.0; //    16
        dX[n]= 5.0;  dY[n++]=-15.0; //    17
        dX[n]=10.0;  dY[n++]=-20.0; //    18
        dX[n]= 5.0;  dY[n++]=-20.0; //    19
        dX[n]= 0.0;  dY[n++]=-15.0; //    20
        dX[n]= 0.0;  dY[n++]=-20.0; //    21
        dX[n]=15.0;  dY[n++]=-20.0; //    22

        connected[n++] = false;     //    23

        dX[n]=15.0;  dY[n++]=-30.0; //    24
        dX[n]=-5.0;  dY[n++]=-20.0; //    25
        dX[n]= 5.0;  dY[n++]=-25.0; //    26
        dX[n]=10.0;  dY[n++]=-25.0; //    27
        dX[n]=15.0;  dY[n++]=-25.0; //    28
        dX[n]=10.0;  dY[n++]=-30.0; //    29
        dX[n]= 5.0;  dY[n++]=-30.0; //    30
        dX[n]= 0.0;  dY[n++]=-25.0; //    31
        dX[n]= 0.0;  dY[n++]=-30.0; //    32
        dX[n]=-5.0;  dY[n++]=-30.0; //    33


        connected[n++] = false;     //    34
        connected[n++] = false;     //    35

        for (int i=0; i<nTaxels; ++i)
        {
            double x=dX[i]-0.0;
            double y=dY[i]-0.0;

            if (lrMirror) x=-x;

            dX[i]=cx+CST*x-SNT*y;
            dY[i]=cy+SNT*x+CST*y;
        }

        dXv[0]=-7.5;  dYv[0]= 2.5;
        dXv[1]=17.5;  dYv[1]=2.5;
        dXv[2]= 17.5;  dYv[3]= -32.5;
        dXv[3]=-7.5;  dYv[2]=-32.5;





        for (int i=0; i<nVerts; ++i)
        {
            double x=dXv[i];
            double y=dYv[i];
            if (lrMirror) x=-x;
            dXv[i]=cx+CST*x-SNT*y;
            dYv[i]=cy+SNT*x+CST*y;
        }

        // in static definition
        //dXmin=dYmin= HUGE;
        //dXmax=dYmax=-HUGE;

        for (int i=0; i<nVerts; ++i)
        {
            if (dXv[i]<dXmin) dXmin=dXv[i];
            if (dXv[i]>dXmax) dXmax=dXv[i];
            if (dYv[i]<dYmin) dYmin=dYv[i];
            if (dYv[i]>dYmax) dYmax=dYv[i];
        }

        dXc=cx;
        dYc=cy;
    }
};

#endif

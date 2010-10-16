using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace GraphicFilling
{
    class Line
    {
        public double X
        {
            get;
            set;
        }
        public Point UpPoint
        {
            get;
            set;
        }

        public Point DownPoint
        {
            get;
            set;
        }

        public float k
        {
            get;
            set;
        }

        public int Ymax
        {
            get;
            set;
        }

        public int Ymin
        {
            get;
            set;
        }

        public Line(Point p1, Point p2)
        {
            if (p1.Y < p2.Y)
            {
                DownPoint = p1;
                UpPoint = p2;
            }
            else
            {
                DownPoint = p2;
                UpPoint = p1;
            }
            if (p1.X != p2.X)
                k = (float)(p1.Y - p2.Y) / (float)(p1.X - p2.X);
            else
                k = 0;
            Ymax = UpPoint.Y;
            Ymin = DownPoint.Y;
            X = DownPoint.X;
        }
    }
}

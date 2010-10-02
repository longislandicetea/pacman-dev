using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace DashedLine
{
    class DashedLine
    {
        private Point beg, end, now, newNow;
        private int nBegX, nEndX;
        private List<Point> points;
        private int a, b, d, delta1, delta2;
        private int direction;
        private Bitmap map;

        private void drawPixel(int posX, int posY, Color color)
        {
            Bitmap tmp = new Bitmap(1, 1);
            for (int i = 0; i < tmp.Width; ++i)
            {
                for (int j = 0; j < tmp.Height; ++j)
                {
                    tmp.SetPixel(i, j, color);
                }
            }
            Graphics g = Graphics.FromImage(map);
            g.DrawImageUnscaled(tmp, posX, posY);
        }

        private void setNewPos(int x, int y)
        {
            newNow.X = x;
            newNow.Y = y;
        }

        private void setOldPos(int x, int y, int direction)
        {
            if (direction == 1)
            {
                now.X = newNow.Y;
                now.Y = newNow.X;
            }
            else if (direction == 2)
            {
                now.X = -newNow.Y;
                now.Y = newNow.X;
            }
            else if (direction == 3)
            {
                now.X = newNow.X;
                now.Y = -newNow.Y;
            }
            else
            {
                now.X = newNow.X;
                now.Y = newNow.Y;
            }
        }

        private void transfer()
        {
            nBegX = beg.X;
            nEndX = end.X;

            //k=0
            if (beg.Y == end.Y)
                ;
            //k>1
            else if (end.Y - beg.Y >= end.X - beg.X)
            {
                setNewPos(now.Y, now.X);
                direction = 1;
                nEndX = end.Y;
                nBegX = beg.Y;
                a = beg.X - end.X;
                b = end.Y - beg.Y;
            }
            //k<-1 
            else if (end.Y - beg.Y <= beg.X - end.X)
            {
                setNewPos(end.Y, -end.X);
                direction = 2;
                nEndX = beg.Y;
                nBegX = end.Y;
                a = beg.X - end.X;
                b = beg.Y - end.Y;
            }
            //-1<k<0
            else if (end.Y < beg.Y && end.Y - beg.Y > beg.X - end.X)
            {
                setNewPos(now.X, -now.Y);
                direction = 3;
                nEndX = end.X;
                nBegX = beg.X;
                a = end.Y - beg.Y;
                b = -beg.X + end.X;
            }
            delta1 = 2 * a;
            delta2 = 2 * (a + b);
            d = 2 * a + b;
        }

        public DashedLine(Point _beg, Point _end, Bitmap _map)
        {
            beg = _beg;
            end = _end;
            now = beg;
            newNow = now;
            a = beg.Y - end.Y;
            b = end.X - beg.X;
            direction = 0;
            map = _map;
            points = null;
            points = GetPoints();
        }

        public void DrawDashedLine()
        {
            int cnt = 0;
            for (int i = 0; i < points.Count; ++i)
            {
                if (cnt < 3)
                    drawPixel(points[i].X, points[i].Y, Color.Red);
                cnt = (cnt + 1) % 6;
            }
        }

        public List<Point> GetPoints()
        {
            if (points != null)
                return points;
            transfer();
            List<Point> tmpPoints = new List<Point>();
            tmpPoints.Add(beg);
            while (newNow.X < nEndX)
            {
                if (d < 0)
                {
                    ++newNow.X;
                    ++newNow.Y;
                    d += delta2;
                }
                else
                {
                    ++newNow.X;
                    d += delta1;
                }
                setOldPos(newNow.X, newNow.Y, direction);
                Point tmp = new Point(now.X, now.Y);
                tmpPoints.Add(tmp);
            }
            return tmpPoints;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace WideLine
{
    class WideLine
    {
        public WideLine(Point _beg, Point _end, int _width,Bitmap _map)
        {
            if (_beg.X > _end.X)
            {
                Point tmp = new Point();
                tmp = _beg;
                _beg = _end;
                _end = tmp;
            }
            beg = _beg;
            end = _end;
            width = _width;
            map = _map;
            begPoints = new List<Point>();
            getBegPoints();
        }
        
        public void DrawWideLine()
        {
            Point tmp = new Point();
            for (int i = 0; i < begPoints.Count; ++i)
            {
                int offsetX = begPoints[i].X - begPoints[0].X;
                int offsetY = begPoints[i].Y - begPoints[0].Y;
                tmp.X = end.X + offsetX;
                tmp.Y = end.Y + offsetY;
                SingleLine line = new SingleLine(begPoints[i], tmp, map);
                line.DrawSingleLine();
            }
        }

        private Point getVerticleEndPoint()
        {
            int va = end.X - beg.X;
            int vb = end.Y - beg.Y;
            Point p = new Point();
            if (vb != 0)
            {
                double k = -(double)va / (double)vb;
                p.X = (int)Math.Round(beg.X + width / Math.Sqrt(k * k + 1));
                p.Y = (int)Math.Round(k * (p.X - beg.X) + beg.Y);
            }
            else
            {
                p.X = beg.X;
                p.Y = beg.Y - width;
            }
            return p;
        }

        private void getBegPoints()
        {
            SingleLine vline = new SingleLine(beg, getVerticleEndPoint(),map);
            begPoints = vline.GetPoints();
        }

        private List<Point> begPoints;
        private Point beg, end;
        private int width;
        private Bitmap map;
    }
}

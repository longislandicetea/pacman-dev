using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace GraphicFilling
{
    class Graphic
    {
        private LinkedList<Line>[] net;
        private LinkedList<Line> aet;
        private List<Point> vertices;
        private List<Line> sides;
        private int upEdge, downEdge;
        private Bitmap map;

        private void constructLine()
        {
            int i;
            for (i = 0; i < vertices.Count - 1; ++i)
            {
                Line tmp = new Line(vertices[i], vertices[i + 1]);
                sides.Add(tmp);
            }
            Line last = new Line(vertices[i], vertices[0]);
            sides.Add(last);
        }
        
        private void preprocess()
        {
            for (int i = 0; i < sides.Count; ++i)
            {
                int id = sides[i].Ymin;
                net[id].AddLast(sides[i]);
            }
        }

        private void drawPixel(Point now)
        {
            Bitmap tmp = new Bitmap(2, 2);
            for (int i = 0; i < 2; ++i)
            {
                for (int j = 0; j < 2; ++j)
                {
                    tmp.SetPixel(i, j, Color.Red);
                }
            }
            Graphics g = Graphics.FromImage(map);
            g.DrawImageUnscaled(tmp, now.X, now.Y);
        }

        public Graphic(List<Point> points,Bitmap _map)
        {
            map = _map;
            aet = new LinkedList<Line>();
            vertices = new List<Point>();
            upEdge = 0;
            downEdge = 100;
            for (int i = 0; i < points.Count; ++i)
            {
                if (points[i].Y > upEdge)
                    upEdge = points[i].Y;
                if (points[i].Y < downEdge)
                    downEdge = points[i].Y;
                vertices.Add(points[i]);
            }
            sides = new List<Line>();
            constructLine();
            net = new LinkedList<Line>[upEdge+1];
            for (int j = 0; j <= upEdge; ++j)
                net[j] = new LinkedList<Line>();
            preprocess();
        }

        public void Fill()
        {
            for(int i = downEdge; i <=upEdge; ++i)
            {
                foreach (Line netNode in net[i])
                {
                    var aetNode = aet.First;
                    if (aetNode == null)
                        aet.AddFirst(netNode);
                    else
                    {
                        if (netNode.X <= aet.First.Value.X)
                            aet.AddFirst(netNode);
                        else if (netNode.X >= aet.Last.Value.X)
                            aet.AddLast(netNode);
                        else
                        {
                            while (aetNode != null)
                            {
                                if (netNode.X > aetNode.Value.X&&netNode.X<aetNode.Next.Value.X)
                                {
                                    aet.AddAfter(aetNode, netNode);
                                    break;
                                }
                                aetNode = aetNode.Next;
                            }
                        }
                    }
                }

                for (int j = (int)aet.First.Value.X; j <= aet.Last.Value.X; ++j)
                {
                    Point now = new Point(j, i);
                    drawPixel(now);
                }

                var tmp = aet.First;
                while (tmp != null)
                {
                    var next = tmp.Next;
                    if (tmp.Value.Ymax == i)
                    {
                        aet.Remove(tmp);
                    }
                    else if (tmp.Value.Ymax > i)
                    {
                        tmp.Value.X += tmp.Value.k == 0.0 ? 0.0 : 1.0 / tmp.Value.k;
                    }
                    tmp = next;
                }
            }
        }
    }
}

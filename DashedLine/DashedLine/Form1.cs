using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DashedLine
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            map = new Bitmap(600, 600);
        }
        private Bitmap map;

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = Graphics.FromHwnd(this.Handle);
            g.DrawImageUnscaled(map, 0, 0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Point beg = new Point(Int32.Parse(this.textBox1.Text), Int32.Parse(this.textBox2.Text));
            Point end = new Point(Int32.Parse(this.textBox3.Text), Int32.Parse(this.textBox4.Text));
            DashedLine line = new DashedLine(beg, end, map);
            line.DrawDashedLine();
            Invalidate();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            map = new Bitmap(600, 600);
            Invalidate();
        }
    }
}

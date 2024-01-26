/****************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** NESNEYE DAYALI PROGRAMLAMA DERSİ
**
** ÖDEV NUMARASI: Odev2 
** ÖĞRENCİ ADI.:  Halit İnce
** ÖĞRENCİ NUMARASI: b171210001
** DERS GRUBU: 1A
****************************************************************************/


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ndp_odev2
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();
            frm1.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            StreamReader dosya = File.OpenText("veriler.txt");
            string[] parcalar;
            string substr;
            char ch;
            int counter = 0;
            string str = dosya.ReadLine();
            while (str != null)
            {
                parcalar = str.Split(' ');
                for(int i = 1; i <= 3; i++)
                {
                    substr = parcalar[0];
                    ch = substr[i-1];
                    richTextBox1.AppendText(parcalar[i]);
                    richTextBox1.AppendText(" ");
                    richTextBox1.Select(richTextBox1.Text.Length - parcalar[i].Length-1, parcalar[i].Length);
                    
                    if (counter % 2 == 0)  richTextBox1.SelectionFont = new Font("Consolas", 12f);
                    else richTextBox1.SelectionFont = new Font("Consolas", 12f, FontStyle.Bold);

                    if      (ch == 'k') richTextBox1.SelectionColor = Color.Red;
                    else if (ch == 'm') richTextBox1.SelectionColor = Color.Blue;
                    else if (ch == 'y') richTextBox1.SelectionColor = Color.Green;
                }
                richTextBox1.AppendText("\n");
                str = dosya.ReadLine();
                counter++;
            }
            dosya.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}

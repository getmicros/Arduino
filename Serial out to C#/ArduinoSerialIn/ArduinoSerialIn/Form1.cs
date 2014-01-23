using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ArduinoSerialIn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            serialPort1.BaudRate = 9600;
            serialPort1.PortName = "COM5";
            serialPort1.Open();
            serialPort1.DataReceived += serialPort1_DataReceived;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string line = serialPort1.ReadLine();
            this.BeginInvoke(new LineReceivedEvent(LineReceived), line);
        }

        private delegate void LineReceivedEvent(string line);
        private void LineReceived(string line)
        {

            label1.Text = line;
            progressBar1.Value = int.Parse(line);
        }
    }
}

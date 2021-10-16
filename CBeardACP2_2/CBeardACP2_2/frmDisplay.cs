using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;
using System.IO;
namespace CBeardACP2_2
{
    public partial class frmDisplay : Form
    {
        SQLiteConnection sqlite_conn;
        static string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "Sneakers.db");

        public frmDisplay()
        {
            InitializeComponent();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            frmMain myForm = new frmMain();
            this.Hide();
            myForm.Show();
            this.Close();
        }

        private void lbxDisplay_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        string myInfo;
        private void frmDisplay_Load(object sender, EventArgs e)
        {
            sqlite_conn = CreateConnection();



            SQLiteDataReader dr;
            SQLiteCommand cmd;
            cmd = sqlite_conn.CreateCommand();
            cmd.CommandText = "SELECT * FROM Sneakers";
            //use reader to get data
            dr = cmd.ExecuteReader();
            lbxDisplay.Items.Add("\tName\t\tBrand\tStyle\tColor\tRetail\tResell\tYear");
            while (dr.Read())
            {
                //must be in same order as the table
                myInfo = dr.GetInt32(0) + "\t" + dr.GetString(1) + "\t" + dr.GetString(2) + "\t" + dr.GetString(3) + "\t" + dr.GetString(4) + "\t" + dr.GetInt32(5) + "\t" + dr.GetInt32(6) + "\t" + dr.GetInt32(7);
                lbxDisplay.Items.Add(myInfo);




            }
        }
        static SQLiteConnection CreateConnection()
        {

            SQLiteConnection sqlite_conn;
            sqlite_conn = new SQLiteConnection("Data Source=" + path);

            //open connection
            try
            {
                sqlite_conn.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            return sqlite_conn;
        }
    }
}

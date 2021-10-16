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
    public partial class frmMain : Form
    {
        SQLiteConnection sqlite_conn;
        static string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "Sneakers.db");


        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            sqlite_conn = CreateConnection();
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
        private void btnCreate_Click(object sender, EventArgs e)
        {
            SQLiteCommand cmd;
            cmd = sqlite_conn.CreateCommand();
            //drop if its already there
            cmd.CommandText = "DROP TABLE IF EXISTS Sneakers";
            cmd.ExecuteNonQuery();
            //create table with 3 columns primary key name year
            cmd.CommandText = @"CREATE TABLE Sneakers (id INTEGER PRIMARY KEY, name TEXT, brand TEXT,style TEXT,color TEXT,retail INT,resell money,year INT)";
            cmd.ExecuteNonQuery();
            MessageBox.Show("Table Created");
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            SQLiteCommand cmd;
            cmd = sqlite_conn.CreateCommand();
            //insert 4 different records into members table
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Red Octobers', 'Nike','Fashion','Red',245,20000, 2014)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Yeezy Boost 750 ', 'Adidas','Fashion','Black',350,1200, 2016)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Jordan 1 Dior', 'Nike','Fashion','White',170,10000, 2020)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Blazer Sacai', 'Nike','Fashion','White',140,350, 2019)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Jaspers', 'Louis V','Fashion','Gray',870,10000, 2009)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Air Mag', 'Nike','Fashion','Gray',2300,50000, 2014)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Chunky Dunky', 'Nike','Fashion','White',100,1500, 2020)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Vlone', 'Nike','Fashion','Black',8000,17000, 2017)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('NMD F&F', 'Adidas','Fashion','Gray',245,10000, 2016)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Macklemore 6', 'Nike','Fashion','Green',20000,25000, 2014)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Eminem 4', 'Nike','Fashion','Black',25000,30000, 2015)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('Milk Crate', 'Nike','Fashion','White',120,1400, 2007)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('350 bred', 'Adidas','Fashion','Black',220,500, 2017)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('FOG Sail', 'Nike','Fashion','Cream',350,700, 2019)";
            cmd.ExecuteNonQuery();
            cmd.CommandText = "INSERT INTO Sneakers(name,brand, style,color,retail,resell,year) VALUES ('380 Alien', 'Adidas','Fashion','White',230,460, 2020)";
            cmd.ExecuteNonQuery();
            MessageBox.Show("Rows Created");

        }
        string myInfo;

        private void btnRead_Click(object sender, EventArgs e)
        {
            frmDisplay displayForm = new frmDisplay();
            displayForm.ShowDialog();
            //could not get this.Hide or this.Close to work
            //it kept hiding all windows
            this.WindowState = FormWindowState.Minimized;
            sqlite_conn.Close();
        }

        private StringBuilder GenerateReport()
        {
            StringBuilder html = new StringBuilder();
            StringBuilder css = new StringBuilder();
            string bodyimg = "<img src=\"https://i.pinimg.com/originals/8b/55/84/8b5584e21564da83c829cccc5fca0259.jpg\" />";

            //www.w3schools.com/css/csssyntax.asp
            css.Append("<style>");
            css.Append("td {padding:5px;text-align:center;font-weight:bold;text-align:center;font-family:Times New Roman;}");
            css.Append("h1{color:Red;font-size:40;}");
            css.Append("</style>");
            

            html.Append("<html>");
            html.Append($"<head>{css}<title>{"Sneakers"}</title></head>");
            html.Append("<body>");
            html.Append($"<h1>{"Sneakers"}</h1>");

            
            html.Append(bodyimg);


            ///////////

           
            SQLiteDataReader dr;
            SQLiteCommand cmd;
            cmd = sqlite_conn.CreateCommand();
            cmd.CommandText = "SELECT * FROM Sneakers";
            //use reader to get data
            dr = cmd.ExecuteReader();
           
           

            css.Append("<style>");
            css.Append("table {border-collapse:collapse;border-spacing:5;}");
            css.Append("tr{border:solid;border-width:1px 0;font-family:Arial;margin:20px;}");
            css.Append("th{font-weight:bold;color:Red;padding:5px;font-family:Arial;margin:20px;text-align:center;}");
            css.Append("</style>");

            html.Append("<table>");
            html.Append($"<tr>{css}<td colspan=10></td></tr>");
            html.Append($"<th>{"Number"}</th>");
            html.Append($"<th>{"Name"}</th>");
            html.Append($"<th>{"Brand"}</th>");
            html.Append($"<th>{"Style"}</th>");
            html.Append($"<th>{"Color"}</th>");
            html.Append($"<th>{"Retail"}</th>");
            html.Append($"<th>{"Resell"}</th>");
            html.Append($"<th>{"Year"}</th>");

            DateTime today = DateTime.Now;
            html.Append(today);

          


            while (dr.Read())
            {
                //must be in same order as the table
                myInfo ="\t\t" +  dr.GetInt32(0) + "\t" + dr.GetString(1) + "\t" + dr.GetString(2) + "\t" + dr.GetString(3)  +"\t" + dr.GetString(4) + "\t" + dr.GetInt32(5) + "\t" + dr.GetInt32(6) + "\t" + dr.GetInt32(7);

                html.Append("<tr>");
                html.Append($"<td>{dr.GetInt32(0)}</td>");
                html.Append($"<td>{dr.GetString(1)}</td>");
                html.Append($"<td>{dr.GetString(2)}</td>");
                html.Append($"<td>{dr.GetString(3)}</td>");
                html.Append($"<td>{dr.GetString(4)}</td>");
                html.Append($"<td>{dr.GetInt32(5)}</td>");
                html.Append($"<td>{dr.GetInt32(6)}</td>");
                html.Append($"<td>{dr.GetInt32(7)}</td>");
                html.Append("</tr>");

            }
          





            html.Append("<tr><td colspan=9><hr/></td></tr>");
            html.Append("</table>");
            html.Append("Created By:Cody Beard");
            html.Append("</body></html>");
            return html;

            //create table data


            
        }
        private void PrintReport(StringBuilder html)
        {
            //write to hardrive using name report.html
            try
            {
                //using statement will automaticallly close a file after opening it
                using (StreamWriter wr = new StreamWriter(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Report.html"))
                {
                    wr.WriteLine(html);
                }
                System.Diagnostics.Process.Start(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Report.html");

            }
            catch(Exception)
            {
                MessageBox.Show("You dont have write permission", "Error System Permissions", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
            //DateTime today = DateTime.Now;
            //using (StreamWriter wr = new StreamWriter($"{today.ToString("yyyy-MM-dd-HHmmss")} - Report.html"))
            //{
            //    wr.WriteLine(html);
            //}
        }
        private void btnReport_Click(object sender, EventArgs e)
        {
            PrintReport(GenerateReport());
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btnAbout_Click(object sender, EventArgs e)
        {
            frmAbout aboutForm = new frmAbout();
            aboutForm.Show();
            this.WindowState = FormWindowState.Minimized;
        }
    }
}

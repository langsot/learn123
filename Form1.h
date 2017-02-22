#pragma once
#include "Form2.h"
#include "stdafx.h"

namespace Сапер2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			for (int row = 0; row <= MR+1; row++)   
			{     
				Pole[row,0] = -3;     
				Pole[row,MC+1] = -3;   
			}  
			for (int col = 0; col <= MC+1; col++)   
			{     
				Pole[0,col] = -3;     
				Pole[MR+1,col] = -3;   
			}  

			 	if (W*MC + 1 >325)
				this->ClientSize = System::Drawing::Size(W*MC + 1,H*MR +  menuStrip1->Height +  1);
			else
				this->ClientSize = System::Drawing::Size(325,H*MR +  menuStrip1->Height +  1);
			newGame();    
			g = panel1->CreateGraphics();
			panel1->Visible=false;
			
		}
			void newGame() 
			{   
			
				int row, col;      
				int n = 0;         
				int k;            
			  
				for (row = 1; row <= MR; row++) 
				for (col = 1; col <= MC; col++)         
					Pole[row,col] = 0;  
 
				Random^ rnd = gcnew Random();  
  
				do   
				{     
					row = rnd->Next(MR) + 1;     
					col = rnd->Next(MC) + 1;  
					if (Pole[row,col] != 9)     
					{       
						Pole[row,col] = 9;       n++;     
					}   
				}   
				while (n != NM);  
				  
				for (row = 1; row <= MR; row++)     
					for (col = 1; col <= MC; col++)       
						if (Pole[row,col] != 9)       
						{         
							k = 0;  
							if (Pole[row-1,col-1] == 9) k++;         
							if (Pole[row-1,col]   == 9) k++;         
							if (Pole[row-1,col+1] == 9) k++;         
							if (Pole[row,col-1]   == 9) k++;         
							if (Pole[row,col+1]   == 9) k++;         
							if (Pole[row+1,col-1] == 9) k++;         
							if (Pole[row+1,col]   == 9) k++;         
							if (Pole[row+1,col+1] == 9) k++;  
							Pole[row,col] = k;       
						}  
			status = 0;      
			nMin   = 0;        
			nFlag  = 0;      
			} 

	
			void showPole(Graphics^ g, int status) 
			{   
				panel1->Visible=true;
				for (int row = 1; row <= MR; row++)     
					for (int col = 1; col <= MC; col++)       
						this->Kletka(g, row, col, status); 
			}  

			void Kletka(Graphics^ g, int row, int col, int status) 
			{
				int x, y;   
				x = (col - 1) * W + 1;   
				y = (row - 1)* H + 1;  
			 
				if (Pole[row,col] < 100)       
					g->FillRectangle(SystemBrushes::ControlLight, x-1, y-1, W, H);  
 
				if (Pole[row,col] >= 100) 
				{     
				   
					if (Pole[row,col] != 109)         
						g->FillRectangle(Brushes::White, x-1, y-1, W, H);     
					else       
					      
						g->FillRectangle(Brushes::Red, x-1, y-1, W, H);  
					      
					      
					if ((Pole[row,col] >= 101) && (Pole[row,col] <= 108))            
						g->DrawString((Pole[row,col]-100).ToString(),gcnew System::Drawing::Font("Tahoma", 10,System::Drawing::FontStyle::Regular),Brushes::Blue, (float)x+3, (float)y+2);   
					
				}  

				if (Pole[row,col] >= 200)       
					this->flag(g, x, y);  
 
				g->DrawRectangle(Pens::Black, x-1, y-1, W, H); 
			} 
		
			void open(int row, int col)
			{
			 
				int x = (col-1)* W + 1, y = (row-1)* H + 1;  
				if (Pole[row,col] == 0)   
				{     
					Pole[row,col] = 100;  
		    
					this->Kletka(g, row, col, status);  
				  
			   
					this->open(row, col-1);     
					this->open(row-1, col);     
					this->open(row, col+1);     
					this->open(row+1, col);  
			  
					this->open(row-1,col-1);     
					this->open(row-1,col+1);     
					this->open(row+1,col-1);     
					this->open(row+1,col+1);   
				}   else     
					if ((Pole[row,col] < 100) && (Pole[row,col] != -3))     
					{       
						Pole[row,col] += 100;       
					    
						this->Kletka(g, row, col, status);     
					} 
			}
		
			void flag(Graphics^ g, int x, int y) 
			{   
				array<Point>^ p = gcnew array<Point>(3);   
				array<Point>^ m = gcnew array<Point>(5);  
		 
				p[0].X = x+2;   
				p[0].Y = y+2;   
				p[1].X = x+15;  
				p[1].Y = y+6;   
				p[2].X = x+2;   
				p[2].Y = y+10;   
				g->FillPolygon(Brushes::Red, p);  
				g->DrawLine(Pens::Black, x+2, y+2, x+2, y+17);  
				m[0].X = x+4;   
				m[0].Y = y+7;   
				m[1].X = x+4;   
				m[1].Y = y+4;   
				m[2].X = x+5;  
				m[2].Y = y+5;   
				m[3].X = x+6;  
				m[3].Y = y+4;   
				m[4].X = x+6;  
				m[4].Y = y+7;   
				g->DrawLines(Pens::White, m); }  
			void mina() 
			{   
				MessageBox::Show("Вы подарволись");				

			} 
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  новаяИграToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  настройкиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  правилаИгрыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel1;

	private:
	static int    
	  MR =40,  
	  MC =40,   
	  NM =10,    
	  W = 20,       
	  H = 20;  
		
	static array<int,2>^ Pole = gcnew array<int,2>(MR + 2,MC + 2); 
  int nMin;  
  int nFlag; 
 
  int status;     
		System::Drawing::Graphics^ g; 
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->новаяИграToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правилаИгрыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->новаяИграToolStripMenuItem, 
				this->настройкиToolStripMenuItem, this->правилаИгрыToolStripMenuItem, this->выходToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(319, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// новаяИграToolStripMenuItem
			// 
			this->новаяИграToolStripMenuItem->Name = L"новаяИграToolStripMenuItem";
			this->новаяИграToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->новаяИграToolStripMenuItem->Text = L"Новая игра";
			this->новаяИграToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::новаяИграToolStripMenuItem_Click);
			// 
			// настройкиToolStripMenuItem
			// 
			this->настройкиToolStripMenuItem->Name = L"настройкиToolStripMenuItem";
			this->настройкиToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->настройкиToolStripMenuItem->Text = L"Настройки";
			this->настройкиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::настройкиToolStripMenuItem_Click);
			// 
			// правилаИгрыToolStripMenuItem
			// 
			this->правилаИгрыToolStripMenuItem->Name = L"правилаИгрыToolStripMenuItem";
			this->правилаИгрыToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->правилаИгрыToolStripMenuItem->Text = L"Правила игры";
			this->правилаИгрыToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::правилаИгрыToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(319, 296);
			this->panel1->TabIndex = 1;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(319, 320);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Сапер";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void новаяИграToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
					newGame();
					showPole(g, status);

			 }
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if (status == 2)     
		
				 return;  
			if (status == 0)     
		   
				status = 1;  
int row,col;  
  row = e->Y/H + 1;   
  col = e->X/W + 1;  
  int x = (col-1)* W + 1,y = (row-1)* H + 1;  
  if (e->Button == System::Windows::Forms::MouseButtons::Left)  
  {        
	  if (Pole[row,col] == 9)     
	  {       
		  Pole[row,col] += 100;      
		  status = 2; 
		  mina();
		  this->panel1->Invalidate();     
	  }     
	  else       
		  if (Pole[row,col] < 9)               
			  this->open(row,col);     
  }     
  if (e->Button == System::Windows::Forms::MouseButtons::Right)     
  {       
      
	  if (Pole[row,col] <= 9) 
{         
	nFlag += 1;  
        if (Pole[row,col] == 9)           
		nMin += 1;  
        Pole[row,col] += 200;  
        if ((nMin == NM) && (nFlag == NM)) 
		{                    
			status = 2;  
			MessageBox::Show("Вы победили");
			this->panel1->Invalidate();         
		}        
		else                    
			this->Kletka(g, row, col, status);       
	  }       
	  else                
		  if (Pole[row,col] >= 200)         
		  {           
			  nFlag -= 1;           
			  Pole[row,col] -= 200;           
			  this->Kletka(g, row, col, status);         
		  }     
	} 
		 }
private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void правилаИгрыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

			  MessageBox::Show( "Число в ячейке показывает ну и хорошо или не очень, сколько мин скрыто вокруг данной ячейки.\n"+
" gh Это число поможет понять вам, где находятся безопасные ячейки, а где находятся бомбы.\n"+
"Если рядом с открытой ячейкой есть пустая ячейка, то она откроется автоматически.\n"+
"Если вы открыли ячейку с миной, то игра проиграна..\n"+
"Что бы пометить ячейку, в которой находится бомба, нажмите её правой кнопкой мыши и там появится флажок.\n"+
"После того, как вы отметите все мины, можно навести курсор на не открытую ячейку и нажать левую кнопку мыши .\n"+ 
"Тогда откроются все свободные ячейки вокруг неё\n"+
"Если в ячейке указано число, оно показывает, сколько мин скрыто в восьми ячейках вокруг данной. \n"+
"Это число помогает понять, где находятся безопасные ячейки.\n"+
"Игра продолжается до тех пор, пока вы не пометите все мины флажками.\n");
		 }
private: System::Void настройкиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  Form2^ frm = gcnew Form2();   
			  frm->ShowDialog();

			  auto f = System::IO::File::OpenText("min.txt");
			  auto s1 = f->ReadToEnd();

			  String^ q1; 
			  q1 = s1;

			 NM=System::Convert::ToInt32(q1->Substring(0,3));
			 MR=MC=System::Convert::ToInt32(q1->Substring(3,2));

			  f->Close();

				this->ClientSize = System::Drawing::Size(W*MC + 1,H*MR +  menuStrip1->Height +  1);
			
			  Form1();
			newGame();
			showPole(g, status);
		 }
};
}


#pragma once

namespace Сапер2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(184, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ОК";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Количество мин:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Размер поля:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(120, 29);
			this->textBox1->MaxLength = 3;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(60, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(120, 69);
			this->textBox2->MaxLength = 2;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(60, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(173, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Значения введены не корректно";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(117, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(181, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Ошибка при присвоении значений";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(196, 75);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Min(16) Max (40)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(214, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Max (999)";
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 173);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"Form2";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройки";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				 label3->Visible=false;
				 label4->Visible=false;
	try
	{
				 int min=0,razm=0;
				 min=System::Convert::ToInt32(textBox1->Text);
				razm=System::Convert::ToInt32(textBox2->Text);
				if ( min>=razm*razm||min<1||razm>40||razm<8)
				{
					label3->Visible=true;
				}
				else
				{
					auto f = System::IO::File::CreateText("min.txt");
					if (min>99)
					f->Write(textBox1->Text);
					else
						if(min>9)
						{
							f->Write("0");
							f->Write(textBox1->Text);
						}
						else
						{
							f->Write("00");
							f->Write(textBox1->Text);
						}
					if(razm>9)
						{
							f->Write(textBox2->Text);
						}
						else
						{
							f->Write("0");
							f->Write(textBox2->Text);
					    }
					f->Close();
					Close();
				}
	}
	catch (FormatException^)
	{
		label4->Visible=true;
	}
		}
	};
}

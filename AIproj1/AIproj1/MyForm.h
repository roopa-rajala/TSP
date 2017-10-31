#pragma once
#include <windows.h>
#include <iostream>
#include "Simple.h"
#include "Sophisticated.h"
#include <string>
namespace AIproj1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RadioButton^  simple_algo;

	private: System::Windows::Forms::RadioButton^  soph;
	private: System::Windows::Forms::RadioButton^  cost_function1;
	private: System::Windows::Forms::RadioButton^  cost_function2;
	private: System::Windows::Forms::RadioButton^  cost_function3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button3;






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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->simple_algo = (gcnew System::Windows::Forms::RadioButton());
			this->soph = (gcnew System::Windows::Forms::RadioButton());
			this->cost_function1 = (gcnew System::Windows::Forms::RadioButton());
			this->cost_function2 = (gcnew System::Windows::Forms::RadioButton());
			this->cost_function3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(21, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ALGORITHM";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(410, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(145, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"COST FUNCTION";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(410, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"CITIES";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(410, 238);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"MEB";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(410, 312);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Seed";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(414, 201);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 22);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(414, 277);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(236, 22);
			this->textBox2->TabIndex = 8;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(412, 346);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(238, 22);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::ForestGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(399, 412);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 38);
			this->button1->TabIndex = 10;
			this->button1->Text = L"FIND";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(502, 412);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 38);
			this->button2->TabIndex = 11;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// simple_algo
			// 
			this->simple_algo->AutoSize = true;
			this->simple_algo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->simple_algo->Location = System::Drawing::Point(25, 47);
			this->simple_algo->Name = L"simple_algo";
			this->simple_algo->Size = System::Drawing::Size(55, 22);
			this->simple_algo->TabIndex = 12;
			this->simple_algo->TabStop = true;
			this->simple_algo->Text = L"SIM";
			this->simple_algo->UseVisualStyleBackColor = true;
			this->simple_algo->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// soph
			// 
			this->soph->AutoSize = true;
			this->soph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->soph->Location = System::Drawing::Point(133, 47);
			this->soph->Name = L"soph";
			this->soph->Size = System::Drawing::Size(72, 22);
			this->soph->TabIndex = 13;
			this->soph->TabStop = true;
			this->soph->Text = L"SOPH";
			this->soph->UseVisualStyleBackColor = true;
			this->soph->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// cost_function1
			// 
			this->cost_function1->AutoSize = true;
			this->cost_function1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->cost_function1->Location = System::Drawing::Point(414, 133);
			this->cost_function1->Name = L"cost_function1";
			this->cost_function1->Size = System::Drawing::Size(48, 22);
			this->cost_function1->TabIndex = 14;
			this->cost_function1->TabStop = true;
			this->cost_function1->Text = L"C1";
			this->cost_function1->UseVisualStyleBackColor = true;
			// 
			// cost_function2
			// 
			this->cost_function2->AutoSize = true;
			this->cost_function2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->cost_function2->Location = System::Drawing::Point(522, 133);
			this->cost_function2->Name = L"cost_function2";
			this->cost_function2->Size = System::Drawing::Size(48, 22);
			this->cost_function2->TabIndex = 15;
			this->cost_function2->TabStop = true;
			this->cost_function2->Text = L"C2";
			this->cost_function2->UseVisualStyleBackColor = true;
			// 
			// cost_function3
			// 
			this->cost_function3->AutoSize = true;
			this->cost_function3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->cost_function3->Location = System::Drawing::Point(602, 133);
			this->cost_function3->Name = L"cost_function3";
			this->cost_function3->Size = System::Drawing::Size(48, 22);
			this->cost_function3->TabIndex = 16;
			this->cost_function3->TabStop = true;
			this->cost_function3->Text = L"C3";
			this->cost_function3->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 12);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(371, 438);
			this->textBox4->TabIndex = 17;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->simple_algo);
			this->panel1->Controls->Add(this->soph);
			this->panel1->Location = System::Drawing::Point(389, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(229, 72);
			this->panel1->TabIndex = 18;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(602, 416);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 32);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(682, 453);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->cost_function3);
			this->Controls->Add(this->cost_function2);
			this->Controls->Add(this->cost_function1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"MyForm";
			this->Text = L"Travelling SalesMan Problem";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		simple_algo->Checked;
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	int no_of_cities,no_of_states,seed ;
	no_of_cities = Convert::ToInt32( textBox1->Text);
	seed = Convert::ToInt32(textBox3->Text);
	no_of_cities = Convert::ToInt32(textBox1->Text);
	no_of_states = Convert::ToInt32(textBox2->Text);
	textBox4->Clear();
	
	if (cost_function1 -> Checked && simple_algo->Checked) {
		
		std::string sum;
		Simple s;
		sum = s.calDistance(no_of_cities,1,seed,no_of_states);
		String^ str2 = gcnew String(sum.c_str());
		textBox4->Text = str2;	
	}
	if (cost_function2->Checked && simple_algo->Checked) {

		std::string sum;
		Simple s;
		sum = s.calDistance(no_of_cities, 2, seed, no_of_states);
		String^ str2 = gcnew String(sum.c_str());
		textBox4->Text = str2;
	}
	if (cost_function3->Checked && simple_algo->Checked) {

		std::string sum;
		Simple s;
		sum = s.calDistance(no_of_cities, 3, seed, no_of_states);
		String^ str2 = gcnew String(sum.c_str());
		textBox4->Text = str2;
	}
	if (cost_function1->Checked && soph->Checked) {

		std::string sum;
		Sophisticated s;
		sum = s.GeneticAlgorithm(no_of_cities, 1, no_of_states);
		String^ str2 = gcnew String(sum.c_str());
		textBox4->Text = str2;
	}
	if (cost_function2->Checked && soph->Checked) {

		std::string sum;
		Sophisticated s;
		sum = s.GeneticAlgorithm(no_of_cities, 2, no_of_states);
		String^ str2 = gcnew String(sum.c_str());
		textBox4->Text = str2;
	}
	if (cost_function3->Checked && soph->Checked) {

		std::string sum;
		Sophisticated s;
		sum = s.GeneticAlgorithm(no_of_cities, 3, no_of_states);
		String^ str2 = gcnew String(sum.c_str());
		textBox4->Text = str2;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
	
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
Application::Restart ();
}
}

; }
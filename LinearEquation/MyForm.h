#pragma once

#include "Gauss.h"
#include <vector>


namespace LinearEquation {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	std::vector<std::vector<double>> equation;

	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void) {
			InitializeComponent();
			
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm() {
			if (components) 
				delete components;
			
		}
	private: System::Windows::Forms::TextBox^ inputBox;
	private: System::Windows::Forms::Label^ varCountLabel;
	private: System::Windows::Forms::Label^ dataLabel;
	private: System::Windows::Forms::Button^ solveButton;
	private: System::Windows::Forms::Label^ solLabel;
	private: System::Windows::Forms::TextBox^ resultBox;
	private: System::Windows::Forms::TextBox^ gaussBox;
	private: System::Windows::Forms::Label^ gaussLabel;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->varCountLabel = (gcnew System::Windows::Forms::Label());
			this->dataLabel = (gcnew System::Windows::Forms::Label());
			this->solveButton = (gcnew System::Windows::Forms::Button());
			this->solLabel = (gcnew System::Windows::Forms::Label());
			this->resultBox = (gcnew System::Windows::Forms::TextBox());
			this->gaussBox = (gcnew System::Windows::Forms::TextBox());
			this->gaussLabel = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// inputBox
			// 
			this->inputBox->BackColor = System::Drawing::SystemColors::Window;
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->inputBox->Location = System::Drawing::Point(25, 101);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->inputBox->Size = System::Drawing::Size(411, 363);
			this->inputBox->TabIndex = 0;
			this->inputBox->Text = L"Input equation here...\r\nas a matrix, sample:\r\n2 2 10\r\n2 -2 4\r\nmean:\r\n2x1 + 2x2 = "
				L"10\r\n2x1 - 2x2 = 4";
			this->inputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::InputBox_KeyPress);
			// 
			// varCountLabel
			// 
			this->varCountLabel->AutoSize = true;
			this->varCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->varCountLabel->Location = System::Drawing::Point(21, 34);
			this->varCountLabel->Name = L"varCountLabel";
			this->varCountLabel->Size = System::Drawing::Size(171, 24);
			this->varCountLabel->TabIndex = 1;
			this->varCountLabel->Text = L"Variable Count: 0";
			// 
			// dataLabel
			// 
			this->dataLabel->AutoSize = true;
			this->dataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dataLabel->Location = System::Drawing::Point(21, 68);
			this->dataLabel->Name = L"dataLabel";
			this->dataLabel->Size = System::Drawing::Size(146, 24);
			this->dataLabel->TabIndex = 2;
			this->dataLabel->Text = L"Equation Data:";
			// 
			// solveButton
			// 
			this->solveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->solveButton->Location = System::Drawing::Point(169, 487);
			this->solveButton->Name = L"solveButton";
			this->solveButton->Size = System::Drawing::Size(113, 38);
			this->solveButton->TabIndex = 3;
			this->solveButton->Text = L"SOLVE";
			this->solveButton->UseVisualStyleBackColor = true;
			this->solveButton->Click += gcnew System::EventHandler(this, &MyForm::SolveButton_Click);
			// 
			// solLabel
			// 
			this->solLabel->AutoSize = true;
			this->solLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->solLabel->Location = System::Drawing::Point(470, 68);
			this->solLabel->Name = L"solLabel";
			this->solLabel->Size = System::Drawing::Size(105, 25);
			this->solLabel->TabIndex = 4;
			this->solLabel->Text = L"Solution:";
			// 
			// resultBox
			// 
			this->resultBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->resultBox->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultBox->Location = System::Drawing::Point(475, 101);
			this->resultBox->Multiline = true;
			this->resultBox->Name = L"resultBox";
			this->resultBox->ReadOnly = true;
			this->resultBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->resultBox->Size = System::Drawing::Size(481, 71);
			this->resultBox->TabIndex = 5;
			// 
			// gaussBox
			// 
			this->gaussBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->gaussBox->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gaussBox->Location = System::Drawing::Point(475, 208);
			this->gaussBox->Multiline = true;
			this->gaussBox->Name = L"gaussBox";
			this->gaussBox->ReadOnly = true;
			this->gaussBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->gaussBox->Size = System::Drawing::Size(481, 223);
			this->gaussBox->TabIndex = 6;
			this->gaussBox->WordWrap = false;
			// 
			// gaussLabel
			// 
			this->gaussLabel->AutoSize = true;
			this->gaussLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gaussLabel->Location = System::Drawing::Point(470, 175);
			this->gaussLabel->Name = L"gaussLabel";
			this->gaussLabel->Size = System::Drawing::Size(265, 25);
			this->gaussLabel->TabIndex = 7;
			this->gaussLabel->Text = L"After Gauss-elimination:";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->Location = System::Drawing::Point(471, 440);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(149, 24);
			this->linkLabel1->TabIndex = 8;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"See step by step";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::LinkLabel1_LinkClicked);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(965, 550);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->gaussLabel);
			this->Controls->Add(this->gaussBox);
			this->Controls->Add(this->resultBox);
			this->Controls->Add(this->solLabel);
			this->Controls->Add(this->solveButton);
			this->Controls->Add(this->dataLabel);
			this->Controls->Add(this->varCountLabel);
			this->Controls->Add(this->inputBox);
			this->Name = L"MyForm";
			this->Text = L"Linear Equation Solver";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: bool getInput() {
		equation.clear();
		// read Equation
		try {
			for (int lineIndex = 0; lineIndex < inputBox->Lines->Length; ++lineIndex) {
				String^ temp = inputBox->Lines[lineIndex];
				array<String^>^ split = temp->Split((array<String^>^)nullptr, StringSplitOptions::RemoveEmptyEntries);
				if (split->Length == 0) continue;
				std::vector<double> currentEquation;
				for (int i = 0; i < split->Length; ++i) {
					double number;
					if (!double::TryParse(split[i], number))
						throw gcnew System::Exception(L"Input was not numeric!\n Ôi bạn ơi, bạn nhập sai kìa");
					currentEquation.push_back(number);
				}
				equation.push_back(currentEquation);
				if (equation.back().size() != equation[0].size())
					throw gcnew System::Exception(L"Equation is not correct!\nRow 1 and row " + Convert::ToString(equation.size()) + " not have same size.");
			}
		} catch (Exception^ e) {
			MessageBox::Show(e->Message, "Wrong Input", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return false;
		}
		return true;
	}
	private: System::Void SolveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!getInput()) return;

		varCountLabel->Text = "Variable Count: " + Convert::ToString(equation[0].size() - 1);
		/* ------ show solution ------ */
		int state = LES::Solve(equation);
		if (state == 0) resultBox->Text = "No solution";
		else if (state == -1) resultBox->Text = "Infinity solution";
		else {
			String^ answer = "";
			for (int i = 0; i < (int)LES::res.size(); ++i) {
				answer += "x" + Convert::ToString(i + 1) + " = " + LES::res[i].ToString();
				answer += i == LES::res.size() - 1 ? "" : ", ";
			}
			resultBox->Text = answer;
		}

		/* ------ set left justified ------ */
		std::vector<int> space(equation[0].size(), 0);
		for (int i = 0; i < equation.size(); ++i) {
			for (int j = 0; j < equation[i].size(); ++j) {
				String^ x = Math::Round(LES::gauss[i][j], 3).ToString();
				int len = x->Length + 3;
				if (space[j] < len)
					space[j] = len;
				
			}
		}
		/* ------ show equation after Gauss-elimination ------ */
		gaussBox->Text = "";
		for (int i = 0; i < equation.size(); ++i) {
			for (int j = 0; j < equation[i].size() - 1; ++j) {
				gaussBox->Text += LES::gauss[i][j].ToString("0.###")->PadLeft(space[j]);
			}
			gaussBox->Text += "  | " + Math::Round(LES::gauss[i].back(), 3).ToString()->PadLeft(space.back() - 3);
			gaussBox->Text += "\r\n";
		}
		
		if (state == -1) { 
			gaussBox->Text += "Free variables: ";
			for (int i = 0; i < LES::where.size(); ++i)
				if (LES::where[i] == -1)
					gaussBox->Text += "x" + Convert::ToString(i + 1) + " ";
		}
		
	}
private: System::Void LinkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start("solution.txt");
}

private: System::Void InputBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	String^ placeHolder = L"Input equation here...\r\nas a matrix, sample:\r\n2 2 10\r\n2 -2 4\r\nmean:\r\n2x1 + 2x2 = "
		L"10\r\n2x1 - 2x2 = 4";
	if (inputBox->Text == placeHolder)
		inputBox->Text = "";
	inputBox->ForeColor = Color::Black;
	
}
};
}

/* note:

*/
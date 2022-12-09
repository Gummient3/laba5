#pragma once
#include <cmath>
#include <iomanip>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	inline bool IsNotAcc(String^ MyRes, String^ Accur)
	{
		MyRes = MyRes->Remove(MyRes->Length - 1);
		return MyRes->EndsWith("0");
	}
	inline  double MyE(double eps, int &count, double X, double sum)
	{
		sum = 1;
		count = 0;
		double a = 1;
		while (fabs(a) > eps)
		{
			count++;
			a = a * X / count;
			sum += a;
		}
		if (count % 2 != 0 && X < 0)
		{
			count++;
			a = a * X / count; 
			sum+= a;
		}
		return sum;
	}
	inline void EPSexp(double& p1, System::String^& OutForm, double& sum, int& count, double X, System::String^& Result , System::String^& Res, Dictionary<String^, String^>^ dict, String^ Accur)
	{
		p1 = Convert::ToDouble(Accur);
		dict->TryGetValue(Accur, OutForm);
		sum = MyE(p1, count, X, sum);


		Result = String::Format(OutForm, sum);
		Res = String::Format(OutForm, exp(X));
	}
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		static array<wchar_t>^ digits = { '0','1','2','3','4','5','6','7','8','9' };
		static String^ Accur = "0,1";
		static Dictionary<String^, String^>^ dict = gcnew Dictionary<String^, String^>;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
			dict->Add("0,1", "{0:F2}");
			dict->Add("0,01", "{0:F3}");
			dict->Add("0,001", "{0:F4}");
			dict->Add("0,0001", "{0:F5}");
			dict->Add("0,00001", "{0:F6}");
			dict->Add("0,000001", "{0:F7}");
		}
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ txtX;
	private: System::Windows::Forms::RadioButton^ rad0_1;
	private: System::Windows::Forms::RadioButton^ rad0_000001;
	private: System::Windows::Forms::RadioButton^ rad0_00001;
	private: System::Windows::Forms::RadioButton^ rad0_0001;
	private: System::Windows::Forms::RadioButton^ rad0_001;
	private: System::Windows::Forms::RadioButton^ rad0_01;
	private: System::Windows::Forms::Button^ btnRes;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblDefaultValue;
	private: System::Windows::Forms::Label^ lblAccuracy;
	private: System::Windows::Forms::Label^ lblExactValue;
	private: System::Windows::Forms::Label^ lblSumCount;
	private: System::Windows::Forms::Label^ lblRowSum;
	private: System::Windows::Forms::Label^ lblDefVal;
	private: System::Windows::Forms::Label^ lblAcc;
	private: System::Windows::Forms::Label^ lblSum;
	private: System::Windows::Forms::Label^ lblExVal;
	private: System::Windows::Forms::Label^ lblCount;
	private: System::Windows::Forms::Button^ btnClose;
	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->rad0_000001 = (gcnew System::Windows::Forms::RadioButton());
			this->rad0_00001 = (gcnew System::Windows::Forms::RadioButton());
			this->rad0_0001 = (gcnew System::Windows::Forms::RadioButton());
			this->rad0_001 = (gcnew System::Windows::Forms::RadioButton());
			this->rad0_01 = (gcnew System::Windows::Forms::RadioButton());
			this->rad0_1 = (gcnew System::Windows::Forms::RadioButton());
			this->btnRes = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblDefaultValue = (gcnew System::Windows::Forms::Label());
			this->lblAccuracy = (gcnew System::Windows::Forms::Label());
			this->lblExactValue = (gcnew System::Windows::Forms::Label());
			this->lblSumCount = (gcnew System::Windows::Forms::Label());
			this->lblRowSum = (gcnew System::Windows::Forms::Label());
			this->lblDefVal = (gcnew System::Windows::Forms::Label());
			this->lblAcc = (gcnew System::Windows::Forms::Label());
			this->lblSum = (gcnew System::Windows::Forms::Label());
			this->lblExVal = (gcnew System::Windows::Forms::Label());
			this->lblCount = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(46, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(249, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"exp(x) = 1 + x/1! + x^2/2! + x^3/3! + ...";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtX);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->groupBox1->Location = System::Drawing::Point(12, 42);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(299, 59);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод значения X (-14<=X<=32)";
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(35, 24);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(258, 20);
			this->txtX->TabIndex = 3;
			this->txtX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtX->TextChanged += gcnew System::EventHandler(this, &Form1::txtX_TextChanged);
			this->txtX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtX_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(6, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"X =";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->rad0_000001);
			this->groupBox2->Controls->Add(this->rad0_00001);
			this->groupBox2->Controls->Add(this->rad0_0001);
			this->groupBox2->Controls->Add(this->rad0_001);
			this->groupBox2->Controls->Add(this->rad0_01);
			this->groupBox2->Controls->Add(this->rad0_1);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->groupBox2->Location = System::Drawing::Point(12, 107);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(299, 68);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Выбор точности";
			// 
			// rad0_000001
			// 
			this->rad0_000001->AutoSize = true;
			this->rad0_000001->ForeColor = System::Drawing::SystemColors::ControlText;
			this->rad0_000001->Location = System::Drawing::Point(214, 42);
			this->rad0_000001->Name = L"rad0_000001";
			this->rad0_000001->Size = System::Drawing::Size(70, 17);
			this->rad0_000001->TabIndex = 5;
			this->rad0_000001->Text = L"0,000001";
			this->rad0_000001->UseVisualStyleBackColor = true;
			this->rad0_000001->Click += gcnew System::EventHandler(this, &Form1::Accuracy);
			// 
			// rad0_00001
			// 
			this->rad0_00001->AutoSize = true;
			this->rad0_00001->ForeColor = System::Drawing::SystemColors::ControlText;
			this->rad0_00001->Location = System::Drawing::Point(214, 19);
			this->rad0_00001->Name = L"rad0_00001";
			this->rad0_00001->Size = System::Drawing::Size(64, 17);
			this->rad0_00001->TabIndex = 4;
			this->rad0_00001->Text = L"0,00001";
			this->rad0_00001->UseVisualStyleBackColor = true;
			this->rad0_00001->Click += gcnew System::EventHandler(this, &Form1::Accuracy);
			// 
			// rad0_0001
			// 
			this->rad0_0001->AutoSize = true;
			this->rad0_0001->ForeColor = System::Drawing::SystemColors::ControlText;
			this->rad0_0001->Location = System::Drawing::Point(113, 42);
			this->rad0_0001->Name = L"rad0_0001";
			this->rad0_0001->Size = System::Drawing::Size(58, 17);
			this->rad0_0001->TabIndex = 3;
			this->rad0_0001->Text = L"0,0001";
			this->rad0_0001->UseVisualStyleBackColor = true;
			this->rad0_0001->Click += gcnew System::EventHandler(this, &Form1::Accuracy);
			// 
			// rad0_001
			// 
			this->rad0_001->AutoSize = true;
			this->rad0_001->ForeColor = System::Drawing::SystemColors::ControlText;
			this->rad0_001->Location = System::Drawing::Point(113, 19);
			this->rad0_001->Name = L"rad0_001";
			this->rad0_001->Size = System::Drawing::Size(52, 17);
			this->rad0_001->TabIndex = 2;
			this->rad0_001->Text = L"0,001";
			this->rad0_001->UseVisualStyleBackColor = true;
			this->rad0_001->Click += gcnew System::EventHandler(this, &Form1::Accuracy);
			// 
			// rad0_01
			// 
			this->rad0_01->AutoSize = true;
			this->rad0_01->ForeColor = System::Drawing::SystemColors::ControlText;
			this->rad0_01->Location = System::Drawing::Point(9, 42);
			this->rad0_01->Name = L"rad0_01";
			this->rad0_01->Size = System::Drawing::Size(46, 17);
			this->rad0_01->TabIndex = 1;
			this->rad0_01->Text = L"0,01";
			this->rad0_01->UseVisualStyleBackColor = true;
			this->rad0_01->Click += gcnew System::EventHandler(this, &Form1::Accuracy);
			// 
			// rad0_1
			// 
			this->rad0_1->AutoSize = true;
			this->rad0_1->Checked = true;
			this->rad0_1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->rad0_1->Location = System::Drawing::Point(9, 19);
			this->rad0_1->Name = L"rad0_1";
			this->rad0_1->Size = System::Drawing::Size(40, 17);
			this->rad0_1->TabIndex = 0;
			this->rad0_1->TabStop = true;
			this->rad0_1->Text = L"0,1";
			this->rad0_1->UseVisualStyleBackColor = true;
			this->rad0_1->CheckedChanged += gcnew System::EventHandler(this, &Form1::rad0_1_CheckedChanged);
			this->rad0_1->Click += gcnew System::EventHandler(this, &Form1::Accuracy);
			// 
			// btnRes
			// 
			this->btnRes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRes->Location = System::Drawing::Point(12, 181);
			this->btnRes->Name = L"btnRes";
			this->btnRes->Size = System::Drawing::Size(299, 32);
			this->btnRes->TabIndex = 3;
			this->btnRes->Text = L"Расчёт exp(x)";
			this->btnRes->UseVisualStyleBackColor = true;
			this->btnRes->Click += gcnew System::EventHandler(this, &Form1::btnRes_Click);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(82, 216);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(170, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Результаты расчёта:";
			// 
			// lblDefaultValue
			// 
			this->lblDefaultValue->Location = System::Drawing::Point(18, 250);
			this->lblDefaultValue->Name = L"lblDefaultValue";
			this->lblDefaultValue->Size = System::Drawing::Size(135, 27);
			this->lblDefaultValue->TabIndex = 5;
			this->lblDefaultValue->Text = L"Исходное значение:";
			// 
			// lblAccuracy
			// 
			this->lblAccuracy->Location = System::Drawing::Point(18, 277);
			this->lblAccuracy->Name = L"lblAccuracy";
			this->lblAccuracy->Size = System::Drawing::Size(135, 27);
			this->lblAccuracy->TabIndex = 10;
			this->lblAccuracy->Text = L"Точность:";
			// 
			// lblExactValue
			// 
			this->lblExactValue->Location = System::Drawing::Point(18, 331);
			this->lblExactValue->Name = L"lblExactValue";
			this->lblExactValue->Size = System::Drawing::Size(135, 27);
			this->lblExactValue->TabIndex = 11;
			this->lblExactValue->Text = L"Точное значение exp(x):";
			// 
			// lblSumCount
			// 
			this->lblSumCount->Location = System::Drawing::Point(18, 358);
			this->lblSumCount->Name = L"lblSumCount";
			this->lblSumCount->Size = System::Drawing::Size(135, 27);
			this->lblSumCount->TabIndex = 12;
			this->lblSumCount->Text = L"Число слагаемых:";
			// 
			// lblRowSum
			// 
			this->lblRowSum->Location = System::Drawing::Point(18, 304);
			this->lblRowSum->Name = L"lblRowSum";
			this->lblRowSum->Size = System::Drawing::Size(135, 27);
			this->lblRowSum->TabIndex = 13;
			this->lblRowSum->Text = L"Сумма ряда exp(x):";
			// 
			// lblDefVal
			// 
			this->lblDefVal->Location = System::Drawing::Point(155, 250);
			this->lblDefVal->Name = L"lblDefVal";
			this->lblDefVal->Size = System::Drawing::Size(135, 27);
			this->lblDefVal->TabIndex = 14;
			// 
			// lblAcc
			// 
			this->lblAcc->Location = System::Drawing::Point(155, 277);
			this->lblAcc->Name = L"lblAcc";
			this->lblAcc->Size = System::Drawing::Size(135, 27);
			this->lblAcc->TabIndex = 15;
			// 
			// lblSum
			// 
			this->lblSum->Location = System::Drawing::Point(155, 304);
			this->lblSum->Name = L"lblSum";
			this->lblSum->Size = System::Drawing::Size(135, 27);
			this->lblSum->TabIndex = 16;
			// 
			// lblExVal
			// 
			this->lblExVal->Location = System::Drawing::Point(155, 331);
			this->lblExVal->Name = L"lblExVal";
			this->lblExVal->Size = System::Drawing::Size(135, 27);
			this->lblExVal->TabIndex = 17;
			// 
			// lblCount
			// 
			this->lblCount->Location = System::Drawing::Point(155, 358);
			this->lblCount->Name = L"lblCount";
			this->lblCount->Size = System::Drawing::Size(135, 27);
			this->lblCount->TabIndex = 18;
			// 
			// btnClose
			// 
			this->btnClose->ForeColor = System::Drawing::Color::Black;
			this->btnClose->Location = System::Drawing::Point(200, 379);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(96, 23);
			this->btnClose->TabIndex = 19;
			this->btnClose->Text = L"Закрыть";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Form1::btnClose_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 414);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->lblCount);
			this->Controls->Add(this->lblExVal);
			this->Controls->Add(this->lblSum);
			this->Controls->Add(this->lblAcc);
			this->Controls->Add(this->lblDefVal);
			this->Controls->Add(this->lblRowSum);
			this->Controls->Add(this->lblSumCount);
			this->Controls->Add(this->lblExactValue);
			this->Controls->Add(this->lblAccuracy);
			this->Controls->Add(this->lblDefaultValue);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnRes);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Расчёт exp(x)";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void txtX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if ((e->KeyChar <= 43 || e->KeyChar >= 58 || e->KeyChar == 47) && e->KeyChar != 8)
			e->Handled = true;
	
		if (e->KeyChar == '.' || e->KeyChar == ',')
		{
			if (txtX->Text->IndexOf('-') != -1)
			{
				if (txtX->Text->IndexOfAny(digits) != -1)
					e->KeyChar = ',';
				
				else
					txtX->Text = L"-0,";
				
			}
			else
			{
				if (txtX->Text->IndexOfAny(digits) != -1)
					e->KeyChar = ',';
				
				else
					txtX->Text = L"0,";
		
			}
			if (txtX->Text->IndexOf(',') != -1)
				e->Handled = true;
			
			txtX->SelectionStart = txtX->Text->Length;
			
		}
		if (e->KeyChar == '-')
		{
			if (txtX->Text->IndexOf('-') != -1)
			{
				e->Handled = true;
				txtX->Text = txtX->Text->Trim('-');
				
				txtX->SelectionStart = txtX->Text->Length;
			}
			else
			{
				e->Handled = true;
				txtX->Text = txtX->Text->Insert(0, "-");
				
				txtX->SelectionStart = txtX->Text->Length;
			}
		}
	}
	private: System::Void txtX_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->lblDefVal->Text = L"";
		this->lblAcc->Text = L"";
		this->lblExVal->Text = L"";
		this->lblSum->Text = L"";
		this->lblCount->Text = L"";
	}
	private: System::Void Accuracy(System::Object^ sender, System::EventArgs^ e) {
		RadioButton^ Accuracy = safe_cast<RadioButton^>(sender);
		Accur = Accuracy->Text;
	}
	private: System::Void btnRes_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->lblDefVal->Text = L"";
		this->lblAcc->Text = L"";
		this->lblExVal->Text = L"";
		this->lblSum->Text = L"";
		this->lblCount->Text = L"";
		if (this->txtX->Text == L"" || this->txtX->Text == L"-")
		{
			MessageBox::Show("Введите значение X", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			this->txtX->Text = L"";
		}
		else if ((32 < Convert::ToDouble(txtX->Text)) || (-14 > Convert::ToDouble(txtX->Text)))
		{
			MessageBox::Show("Превышен диапазон значений X", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			this->txtX->Text = L"";
		}
		else
		{
			String^ OutForm; // Формат вывода
			String^ MyRes; // Результат самописной функции
			String^ LibRes; // Результат библиотечной функции
			double eps; // Точность eps
			double s; // Сумма ряда
			int count; // Число слагаемых
			double X = Convert::ToDouble(txtX->Text);

			EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);

			
			if (X > 0 && MyRes->EndsWith("00"))
			{
				MessageBox::Show("Точность была снижена!", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				while (MyRes->EndsWith("00"))
				{
					if (rad0_000001->Checked)
					{
						rad0_00001->Checked = true;
						Accur = rad0_00001->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_00001->Checked)
					{
						rad0_0001->Checked = true;
						Accur = rad0_0001->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_0001->Checked)
					{
						rad0_001->Checked = true;
						Accur = rad0_001->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_001->Checked)
					{
						rad0_01->Checked = true;
						Accur = rad0_01->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_01->Checked)
					{
						rad0_1->Checked = true;
						Accur = rad0_1->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
				}
			}
			if (X < 0 && IsNotAcc(MyRes, Accur))
			{
				MessageBox::Show("Точность была повышена!", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				while (IsNotAcc(MyRes, Accur))
				{
					if (rad0_1->Checked)
					{
						rad0_01->Checked = true;
						Accur = rad0_01->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_01->Checked)
					{
						rad0_001->Checked = true;
						Accur = rad0_001->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_001->Checked)
					{
						rad0_0001->Checked = true;
						Accur = rad0_0001->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_0001->Checked)
					{
						rad0_00001->Checked = true;
						Accur = rad0_00001->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
					if (rad0_00001->Checked)
					{
						rad0_000001->Checked = true;
						Accur = rad0_000001->Text;
						EPSexp(eps, OutForm, s, count, X, MyRes, LibRes, dict, Accur);
						continue;
					}
				}
			}
			
			lblDefVal->Text = txtX->Text;
			lblAcc->Text = Accur;
			lblCount->Text = Convert::ToString(count);
			lblSum->Text = String::Format(OutForm, s);
			lblExVal->Text = String::Format(OutForm, exp(X));
		}
	}
	private: System::Void rad0_1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

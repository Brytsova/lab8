#pragma once
#include <cstdlib>
#include <ctime>
using namespace std;
namespace lab8 {

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
			srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел
			count = 0; // Инициализация счетчика элементов

		}
	private:
		System::Collections::Generic::Stack<int>^ myStack1 = gcnew System::Collections::Generic::Stack<int>(); // объявление стека
		int count; // количество элементов в стеке
		int limit = 10; // лимит для стека (можно задать другое значение)

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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(51, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(562, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Створити стек цілих чисел. Обчислити суму елементів стеку, які менші 5.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Location = System::Drawing::Point(51, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(172, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Введіть розмір стеку:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(247, 121);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 2;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(66, 171);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(281, 324);
			this->listBox1->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Yellow;
			this->button1->Location = System::Drawing::Point(364, 171);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 83);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Додати елементи до списку";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Yellow;
			this->button2->Location = System::Drawing::Point(364, 293);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 62);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Видалити елементи";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Yellow;
			this->button3->Location = System::Drawing::Point(364, 400);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 54);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Обчислити";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(676, 562);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Перевірка на ініціалізацію textBox1 та listBox1
		if (textBox1 == nullptr || listBox1 == nullptr) {
			MessageBox::Show("Не ініціалізовані елементи інтерфейсу.");
			return;
		}

		int size = Convert::ToInt32(textBox1->Text);

		// Перевірка, чи не досягнуто ліміту
		if (count < size) {
			int randomValue;
			do {
				randomValue = rand() % 100; // Генерація випадкового числа до 100
			} while (randomValue >= 15); // Повторити, якщо число >= 15

			myStack1->Push(randomValue); // Додаємо число менше 15
			listBox1->Items->Insert(0, randomValue.ToString()); // Відображаємо в ListBox
			count++;
		}
		else {
			MessageBox::Show("Досягнуто ліміт чисел");
		};
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (myStack1->Count > 0) {
			myStack1->Pop(); // Видалення верхнього елемента стеку
			if (listBox1->Items->Count > 0) {
				listBox1->Items->RemoveAt(0); // Видалення першого елемента
			}
			count--; // Зменшуємо лічильник
		}
		else {
			listBox1->Items->Add("Стек пустий");
		};
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int sum = 0;

		// Підрахунок суми елементів, які менші 5
		for each (int value in myStack1) {
			if (value < 5) {
				sum += value;
			}
		}

		MessageBox::Show("Сума елементів стеку, які менші 5: " + sum.ToString());
	}
};
}
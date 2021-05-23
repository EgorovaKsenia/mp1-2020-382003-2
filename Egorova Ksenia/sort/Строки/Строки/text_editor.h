#pragma once
#include <locale>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TextEditor {
private:
	vector <string> original_text, edited_text, dict;
public:
	void load_from_file(string name_in, string name_dict) {
		string line, symbol, word = "";

		ifstream ifs;
		ifs.open(name_in);
		while (!ifs.eof()) {
			ifs >> line;
			line += " ";
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '.' || line[i] == '!' || line[i] == '?' || line[i] == ' ') {
					if (word != "") {
						original_text.push_back(word);
					}
					symbol = line[i];
					original_text.push_back(symbol);
					word = "";
				}
				else {
					word += line[i];
				}
			}
		}
		ifs.close();

		ifs.open(name_dict);
		while (!ifs.eof()) {
			ifs >> line;
			dict.push_back(line);
		}
		ifs.close();
	}

	void save_to_file(string name) {
		ofstream ofs;
		ofs.open(name);
		for (int i = 0; i < edited_text.size(); i++) {
			if (edited_text[i] == "." || edited_text[i] == "!" || edited_text[i] == "?") {
				ofs << edited_text[i] << '\n';
				i++;
			}
			else {
				ofs << edited_text[i];
			}
		}
		ofs.close();
	}

	void find_mistakes() {
		setlocale(LC_ALL, "russian");
		edited_text = original_text;
		for (int i = 0; i < original_text.size(); i++) {
			if (!(original_text[i] == "." || original_text[i] == "!" || original_text[i] == "?" || original_text[i] == " ")) {
				string word = "";
				for (int j = 0; j < original_text[i].length(); j++) {
					word += tolower(original_text[i][j]);
				}
				auto result = find(dict.begin(), dict.end(), word);
				if (result == dict.end()) {
					edited_text[i] = "*" + original_text[i];
				}
			}
		}
	}

	int levenshtein_distance(string source, string target) {
		int n = source.length(), m = target.length();
		if (n > m) {
			swap(source, target);
			swap(n, m);
		}

		vector<int> current_row(n + 1);
		vector<int> previous_row(n + 1);
		for (int i = 1; i <= m; i++) {
			for (int l = 0; l <= n; l++) {
				previous_row[l] = current_row[l];
			}
			current_row[0] = i;
			for (int k = 1; k <= n; k++) {
				current_row[k] = 0;
			}
			for (int j = 1; j <= n; j++) {
				int add = previous_row[j] + 1, del = current_row[j - 1] + 1, change = previous_row[j - 1];
				if (source[j - 1] != target[i - 1]) {
					change++;
				}
				current_row[j] = min(min(add, del), change);
			}
		}
		return current_row[n];
	}

	void correct_mistakes() {
		for (int i = 0; i < edited_text.size(); i++) {
			if (edited_text[i][0] == '*') {
				string word = "";
				for (int j = 1; j < edited_text[i].length(); j++) {
					word += tolower(edited_text[i][j]);
				}
				for (int k = 0; k < dict.size(); k++) {
					if (levenshtein_distance(word, dict[k]) == 1) {
						edited_text[i] = dict[k];
					}
				}
			}
		}
	}
};
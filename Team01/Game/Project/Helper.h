#pragma once


#include <fstream>
#include <sstream>

#include "rapidjson/document.h"


static bool ParseJsonDocument(const char* path, rapidjson::Document& document) {
	std::ifstream file(path);
	// ファイルを開けないならfalseを返す
	if (!file.is_open()) {
		return false;
	} // if
	// 読み込み
	std::stringstream stream;
	stream << file.rdbuf();
	std::string temp = stream.str();
	rapidjson::StringStream str(temp.c_str());
	document.ParseStream(str);
	return true;
}
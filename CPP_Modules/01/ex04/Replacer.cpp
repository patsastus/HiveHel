#include "Replacer.hpp"

void Replacer::searchAndReplace(std::ifstream& infile, std::ofstream& outfile, const std::string& target, const std::string& replacement)
{
	if (target.empty() || target.length() > 1000000){
		outfile << infile.rdbuf();
		return ;
	}
	const size_t	BUFFERSIZE = 1024;
	char			readBuffer[BUFFERSIZE];
	std::string		textBuffer = "";
	size_t			overlapMin = target.length() - 1;

	while (infile){
		infile.read(readBuffer, BUFFERSIZE);
		std::streamsize bytesRead = infile.gcount();//gcount returns length of the last operation that read the stream, in this case read()
		textBuffer.append(readBuffer, bytesRead); 	//so we know how much to append to string
		size_t startIndex = 0, tempIndex = 0;
		while ((tempIndex = textBuffer.find(target, startIndex)) != std::string::npos){
			outfile.write(&textBuffer[startIndex], tempIndex - startIndex);
			outfile << replacement;
			startIndex = tempIndex + target.length();
		}
		if (textBuffer.length() > overlapMin) {
			size_t lastIndex = textBuffer.length() - overlapMin;
			if (startIndex < lastIndex) {
				outfile.write(&textBuffer[startIndex], lastIndex - startIndex);
				startIndex = lastIndex;
			}
		}
		textBuffer.erase(0, startIndex);
	}
	outfile << textBuffer;
	return ;
}

int Replacer::run(int argc, char *argv[]){
	if (argc != 4)
		std::cout << "Usage : " << argv[0] << " <filename> <str1> <str2>" << std::endl;
	else
	{
		std::string suffix{".replace"};
		std::filesystem::path filepath = argv[1];
		std::ifstream file(filepath, std::ios::binary); //binary flag means line breaks aren't changed to system specific ones
		if (!file.is_open()) {
			std::cout << "failed to open " << filepath << std::endl;
			return 1;
		}
		else 
		{
			std::filesystem::path outpath = filepath.string() + suffix; //needed to convert path to string to easily add suffix, then assignment converts back to path
			std::ofstream outfile(outpath, std::ios::binary);
			if (outfile.is_open()) {
				Replacer::searchAndReplace(file, outfile, argv[2], argv[3]);
			} else {
				std::cout << "failed to open " << outpath << std::endl;
				return 1;
			}
		}
		return 0;
	}
	return 1;
}


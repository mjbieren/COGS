#include "GlobalHelper.h"

/*
1) Loop over the filtered fasta file.
2) Go one by one and check if the file exist in folder 1 or 2. 
3) If it exist we Copy the file to the output directory
	By opening the file with file handle.
4) Continue to the next item in the list

*/

long PhyloPyPrunerSourcesProcess(std::vector<std::string*>* pvecOrthoGroupNamesFromSetOneAndTwoFiltered)
{
	long lReturn = ERR_NOERROR;

	std::string strOutputDir;
	lReturn = glb.propertyBag.GetOutputDir(&strOutputDir);
	if (lReturn != ERR_NOERROR)
		return PROPERTYBAG_OUTPUTDIR_COGS;

	std::string strInputDirSetOne;
	lReturn = glb.propertyBag.GetPPPInputDirSet1(&strInputDirSetOne);
	if (lReturn != ERR_NOERROR)
		return PROPERTYBAG_PPPINPUTDIRONE_COGS;

	std::string strInputDirSetTwo;
	lReturn = glb.propertyBag.GetPPPInputDirSet2(&strInputDirSetTwo);
	if (lReturn != ERR_NOERROR)
		return PROPERTYBAG_PPPINPUTDIRTWO_COGS;

	FILE* hFILEFileToMove = nullptr;

	size_t sizeVector = pvecOrthoGroupNamesFromSetOneAndTwoFiltered->size();

	std::string strFileName;
	std::string strFullFileNamePath;
	std::string strFullCommand;

	errno_t errFopen_s;

	std::string strTreeFileNameSet1;
	std::string strTreeFileNameSet2;

	//Step ONE
	for (size_t idx = 0; idx < sizeVector; idx++)
	{
		//STEP TWO
		strFileName = *pvecOrthoGroupNamesFromSetOneAndTwoFiltered->at(idx);

		//STEP THREE
		if (idx % 10 == 0) //We do not want to print out that we are writing a file for each file only every 50.
			printf_s("Working on file %zu out of %zu %s", idx, sizeVector, EOL);

		std::string strTreeFileNameCopyCommandSet1 ="cp "+ strInputDirSetOne + strFileName + ".treefile " + strOutputDir;
		std::string strTreeFileNameCopyCommandSet2 ="cp "+ strInputDirSetTwo + strFileName + ".treefile " + strOutputDir;
		//Check first .fa for both set 1 and 2, since those are the most likely hits.
		//Set One
		strFullFileNamePath = strInputDirSetOne + strFileName + ".fa";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet1.c_str());
			continue;
		}
		strFullFileNamePath = strInputDirSetTwo + strFileName + ".fa";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet2.c_str());
			continue;
		}

		//Now the others .fasta, .fna, .ffn, .faa, .frn, .pep


		//.pep
		strFullFileNamePath = strInputDirSetOne + strFileName + ".pep";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet1.c_str());
			continue;
		}
		strFullFileNamePath = strInputDirSetTwo + strFileName + ".pep";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet2.c_str());
			continue;
		}

		//.faa
		strFullFileNamePath = strInputDirSetOne + strFileName + ".faa";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet1.c_str());
			continue;
		}
		strFullFileNamePath = strInputDirSetTwo + strFileName + ".faa";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet2.c_str());
			continue;
		}

		//.fasta
		strFullFileNamePath = strInputDirSetOne + strFileName + ".fasta";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet1.c_str());
			continue;
		}
		strFullFileNamePath = strInputDirSetTwo + strFileName + ".fasta";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet2.c_str());
			continue;
		}


		//.fna
		strFullFileNamePath = strInputDirSetOne + strFileName + ".fna";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet1.c_str());
			continue;
		}
		strFullFileNamePath = strInputDirSetTwo + strFileName + ".fna";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet2.c_str());
			continue;
		}

		//.ffn
		strFullFileNamePath = strInputDirSetOne + strFileName + ".ffn";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet1.c_str());
			continue;
		}
		strFullFileNamePath = strInputDirSetTwo + strFileName + ".ffn";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet2.c_str());
			continue;
		}
		
		//.frn
		strFullFileNamePath = strInputDirSetOne + strFileName + ".frn";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet1.c_str());
			continue;
		}
		strFullFileNamePath = strInputDirSetTwo + strFileName + ".frn";
		errFopen_s = fopen_s(&hFILEFileToMove, strFullFileNamePath.c_str(), "r");
		if (errFopen_s == ERR_NOERROR) //we have a hit :)
		{
			fclose(hFILEFileToMove);
			strFullCommand = "cp " + strFullFileNamePath + " " + strOutputDir;
			system(strFullCommand.c_str());
			system(strTreeFileNameCopyCommandSet2.c_str());
			continue;
		}


		//At this point we couldn't find the file.
		printf_s("File %s couldn't be found in either of the two PhyloPyPruner input folders %s", strFileName);
	}


	return lReturn;
}

#include"domain.h"
#include"RepositoryFile.h"
//#include"Tests.h"
#include"Service.h"
#include<assert.h>
/*

void test_add_repo_inexistingStatue_addedToFile_LenghtIncreased() {

	ofstream myfile;
	myfile.open ("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> statues;
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));
	assert(Repo.GetSizeRepo() == 1);
	myfile.close();
}
void test_add_repo_inexistingStatue_addedToFile_FineStatue() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> statues;
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));
	assert(Repo.GetStatues().front()== GuardianStatue("1", "", 0, ""));
	myfile.close();
}
void test_add_repo_existingStatue_NotAddedToFile()
{
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> statues;
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));
	try {
		Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));}catch (...) {};
	assert(Repo.GetSizeRepo()==1);
	myfile.close();
}
void test_update_repo_existingStatue_UpdatedMaterial() 
{
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));
	Repo.update_repo(GuardianStatue("1", "bb", 6, "dd"));
	assert(Repo.GetStatues().front().GetMaterial().compare("bb") == 0);
	myfile.close();
}
void test_update_repo_existingStatue_UpdatedAge() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));
	Repo.update_repo(GuardianStatue("1", "bb", 6, "dd"));
	assert(Repo.GetStatues().front().GetAge()==6);
	myfile.close();
}
void test_update_repo_existingStatue_UpdatedCorporealForm() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));
	Repo.update_repo(GuardianStatue("1", "bb", 6, "dd"));
	assert(Repo.GetStatues().front().GetCorporealForm().compare("dd")==0);
	myfile.close();
}
void test_update_repo_inexistingStatue_NotUpdated()
{
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	try {
		Repo.update_repo(GuardianStatue("1", "bb", 6, "dd"));
		assert(Repo.GetStatues().front().GetCorporealForm().compare("dd") == 0);}
	catch (...) {};
	myfile.close();
}
void test_delete_repo_existingStatue_deletedFromFile() {

	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 7, "bb"));
	Repo.delete_repo(GuardianStatue("1", "", 0, ""));
	assert(Repo.GetSizeRepo()==0);
	myfile.close();
}
void test_delete_repo_inexistingStatue_NotDeletedFromFile() {

	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 6, "cc"));
	try {
		Repo.delete_repo(GuardianStatue("2", "", 0, ""));
	}
	catch (...) {};
	assert(Repo.GetSizeRepo() == 1);
	myfile.close();
}
void test_save_repo_existingStatue_saved() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 6, "cc"));
	Repo.save_repo(GuardianStatue("1", "", 0, ""));
	assert(Repo.GetSizeMyList() == 1);
	myfile.close();
}
void test_save_repo_existingStatue_FineSavedStatue() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 6, "cc"));
	Repo.save_repo(GuardianStatue("1", "", 0, ""));
	assert(Repo.GetSavedStatues().front()== GuardianStatue("1", "aa", 6, "cc"));
	myfile.close();
}
void test_save_repo_inexistingStatue_NotSaved() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	try {
		Repo.save_repo(GuardianStatue("1", "", 0, ""));
	}catch (...) {};
	assert(Repo.GetSizeMyList() == 0);
	myfile.close();

}
void test_search_repo_existingStatue_FineStatue()
{
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 6, "cc"));
	GuardianStatue statue = Repo.search_repo(GuardianStatue("1", "", 0, ""));
	assert(statue.GetPowerWordName().compare("1") == 0);
	myfile.close();
}
void next_repo_existingStatue_FineStatue()
{
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 6, "cc"));
	Repo.next_repo();

	assert(Repo.get_current() == GuardianStatue("1", "aa", 6, "cc"));
	myfile.close();

}
void test_next_repo_SecondStatue_FineStatue()
{
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Repo.add_repo(GuardianStatue("1", "aa", 6, "cc"));
	Repo.add_repo(GuardianStatue("2", "aa", 6, "cc"));
	Repo.next_repo();
	Repo.next_repo();

	assert(Repo.get_current() == GuardianStatue("1", "aa", 6, "cc"));

	myfile.close();
}
void test_addGuardainStatue_validInput_addedToFile() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Service service(&Repo);
	service.addGuardainStatue("1", "aaa", 4, "bbb");
	assert(service.Get_Statues().front() == GuardianStatue("1", "aaa", 4, "bbb"));
	myfile.close();
}
void test_saveGuardianStatue_validInput_saved() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Service service(&Repo);
	service.addGuardainStatue("1", "aaa", 4, "bbb");
	service.saveGuardianStatue("1");
	assert(service.GetSavedStatues().front()==GuardianStatue("1","",0,""));
	myfile.close();
}
void test_deleteGuardianStatue_validInput_deleted() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Service service(&Repo);
	service.addGuardainStatue("1", "aaa", 4, "bbb");
	service.deleteGuardianStatue("1");
	assert(service.GetNumberStatues()==0);
	myfile.close();
}
void test_updateGuardianStatue_validInput_updated() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Service service(&Repo);
	service.addGuardainStatue("1", "aaa", 4, "bbb");
	service.updateGuardianStatue("1", "AAA", 4, "bbb");
	assert(service.Get_Statues().front().toString().compare("PowerWordName: 1 Material: AAA Age: 4 Corporeal Form: bbb")==0);	myfile.close();
	myfile.close();

}
void test_Next_ValidInput_FineStatue() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Service service(&Repo);
	service.addGuardainStatue("1", "aaa", 4, "bbb");
	
	assert(service.Next().GetPowerWordName().compare("1") == 0);
	myfile.close();
}
void test_searchStatueWithPowerWordName_validInput_FineStatue() {
	ofstream myfile;
	myfile.open("File.txt");
	std::string path = "C:\\Users\\MADA\\source\\repos\\LAB6OOP\\LAB6OOP\\File.txt";
	vector<GuardianStatue> SaveStatues;
	RepoFile Repo(path, SaveStatues);
	Service service(&Repo);
	service.addGuardainStatue("1", "aaa", 4, "bbb");

	assert(service.searchStatueWithPowerWordName("1").GetPowerWordName().compare("1") == 0);
	myfile.close();
}

void test_all()

{
	
	
	test_add_repo_inexistingStatue_addedToFile_LenghtIncreased();
	 test_add_repo_inexistingStatue_addedToFile_FineStatue();
	 test_add_repo_existingStatue_NotAddedToFile();
	 test_update_repo_existingStatue_UpdatedAge();
	 test_update_repo_existingStatue_UpdatedCorporealForm();
	 test_update_repo_existingStatue_UpdatedMaterial();
	 test_update_repo_inexistingStatue_NotUpdated();
	 test_delete_repo_existingStatue_deletedFromFile();
	 test_delete_repo_inexistingStatue_NotDeletedFromFile();
	 test_save_repo_existingStatue_saved();
	 test_save_repo_inexistingStatue_NotSaved();
	 test_search_repo_existingStatue_FineStatue();
	 next_repo_existingStatue_FineStatue();
	 test_save_repo_existingStatue_FineSavedStatue();
	 test_next_repo_SecondStatue_FineStatue();
	 next_repo_existingStatue_FineStatue();
	 test_addGuardainStatue_validInput_addedToFile();
	 test_saveGuardianStatue_validInput_saved();
	 test_deleteGuardianStatue_validInput_deleted();
	 test_updateGuardianStatue_validInput_updated();
	 test_Next_ValidInput_FineStatue();
	 test_searchStatueWithPowerWordName_validInput_FineStatue();
}*/
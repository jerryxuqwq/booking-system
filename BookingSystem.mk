##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=BookingSystem
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/jerry/Documents/booking-system
ProjectPath            :=/home/jerry/Documents/booking-system
IntermediateDirectory  :=./build-$(ConfigurationName)/
OutDir                 :=./build-$(ConfigurationName)/
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jerry
Date                   :=12/03/20
CodeLitePath           :=/home/jerry/.codelite
LinkerName             :=/usr/bin/g++-10
SharedObjectLinkerName :=/usr/bin/g++-10 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            := $(shell pkg-config --libs gtkmm-3.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)/usr/include/mysql++/ $(IncludeSwitch)/usr/include/mariadb/server/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mysqlpp 
ArLibs                 :=  "libmysqlpp" 
LibPath                := $(LibraryPathSwitch)/usr/include/mysql++/ $(LibraryPathSwitch)/usr/include/mariadb/server/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-10
CC       := /usr/bin/gcc-10
CXXFLAGS :=  -g -Wall -O0 $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=./build-$(ConfigurationName)//src_Appointment.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_UserPage.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//main.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_Windows.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_LoginPage.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_User.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_Global.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_Report.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_StudentPage.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//src_Rooms.cpp$(ObjectSuffix) \
	./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ./build-$(ConfigurationName)//.d $(Objects) 
	@mkdir -p "./build-$(ConfigurationName)/"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "./build-$(ConfigurationName)/"
	@mkdir -p ""./build-$(ConfigurationName)/bin""

./build-$(ConfigurationName)//.d:
	@mkdir -p "./build-$(ConfigurationName)/"

PreBuild:


##
## Objects
##
./build-$(ConfigurationName)//src_Appointment.cpp$(ObjectSuffix): src/Appointment.cpp ./build-$(ConfigurationName)//src_Appointment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/Appointment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Appointment.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_Appointment.cpp$(DependSuffix): src/Appointment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_Appointment.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_Appointment.cpp$(DependSuffix) -MM src/Appointment.cpp

./build-$(ConfigurationName)//src_Appointment.cpp$(PreprocessSuffix): src/Appointment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_Appointment.cpp$(PreprocessSuffix) src/Appointment.cpp

./build-$(ConfigurationName)//src_UserPage.cpp$(ObjectSuffix): src/UserPage.cpp ./build-$(ConfigurationName)//src_UserPage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/UserPage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_UserPage.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_UserPage.cpp$(DependSuffix): src/UserPage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_UserPage.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_UserPage.cpp$(DependSuffix) -MM src/UserPage.cpp

./build-$(ConfigurationName)//src_UserPage.cpp$(PreprocessSuffix): src/UserPage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_UserPage.cpp$(PreprocessSuffix) src/UserPage.cpp

./build-$(ConfigurationName)//main.cpp$(ObjectSuffix): main.cpp ./build-$(ConfigurationName)//main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//main.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//main.cpp$(DependSuffix) -MM main.cpp

./build-$(ConfigurationName)//main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//main.cpp$(PreprocessSuffix) main.cpp

./build-$(ConfigurationName)//src_Windows.cpp$(ObjectSuffix): src/Windows.cpp ./build-$(ConfigurationName)//src_Windows.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/Windows.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Windows.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_Windows.cpp$(DependSuffix): src/Windows.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_Windows.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_Windows.cpp$(DependSuffix) -MM src/Windows.cpp

./build-$(ConfigurationName)//src_Windows.cpp$(PreprocessSuffix): src/Windows.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_Windows.cpp$(PreprocessSuffix) src/Windows.cpp

./build-$(ConfigurationName)//src_LoginPage.cpp$(ObjectSuffix): src/LoginPage.cpp ./build-$(ConfigurationName)//src_LoginPage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/LoginPage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LoginPage.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_LoginPage.cpp$(DependSuffix): src/LoginPage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_LoginPage.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_LoginPage.cpp$(DependSuffix) -MM src/LoginPage.cpp

./build-$(ConfigurationName)//src_LoginPage.cpp$(PreprocessSuffix): src/LoginPage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_LoginPage.cpp$(PreprocessSuffix) src/LoginPage.cpp

./build-$(ConfigurationName)//src_User.cpp$(ObjectSuffix): src/User.cpp ./build-$(ConfigurationName)//src_User.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/User.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_User.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_User.cpp$(DependSuffix): src/User.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_User.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_User.cpp$(DependSuffix) -MM src/User.cpp

./build-$(ConfigurationName)//src_User.cpp$(PreprocessSuffix): src/User.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_User.cpp$(PreprocessSuffix) src/User.cpp

./build-$(ConfigurationName)//src_Global.cpp$(ObjectSuffix): src/Global.cpp ./build-$(ConfigurationName)//src_Global.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/Global.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Global.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_Global.cpp$(DependSuffix): src/Global.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_Global.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_Global.cpp$(DependSuffix) -MM src/Global.cpp

./build-$(ConfigurationName)//src_Global.cpp$(PreprocessSuffix): src/Global.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_Global.cpp$(PreprocessSuffix) src/Global.cpp

./build-$(ConfigurationName)//src_Report.cpp$(ObjectSuffix): src/Report.cpp ./build-$(ConfigurationName)//src_Report.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/Report.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Report.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_Report.cpp$(DependSuffix): src/Report.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_Report.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_Report.cpp$(DependSuffix) -MM src/Report.cpp

./build-$(ConfigurationName)//src_Report.cpp$(PreprocessSuffix): src/Report.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_Report.cpp$(PreprocessSuffix) src/Report.cpp

./build-$(ConfigurationName)//src_StudentPage.cpp$(ObjectSuffix): src/StudentPage.cpp ./build-$(ConfigurationName)//src_StudentPage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/StudentPage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_StudentPage.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_StudentPage.cpp$(DependSuffix): src/StudentPage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_StudentPage.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_StudentPage.cpp$(DependSuffix) -MM src/StudentPage.cpp

./build-$(ConfigurationName)//src_StudentPage.cpp$(PreprocessSuffix): src/StudentPage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_StudentPage.cpp$(PreprocessSuffix) src/StudentPage.cpp

./build-$(ConfigurationName)//src_Rooms.cpp$(ObjectSuffix): src/Rooms.cpp ./build-$(ConfigurationName)//src_Rooms.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/Rooms.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Rooms.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_Rooms.cpp$(DependSuffix): src/Rooms.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_Rooms.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_Rooms.cpp$(DependSuffix) -MM src/Rooms.cpp

./build-$(ConfigurationName)//src_Rooms.cpp$(PreprocessSuffix): src/Rooms.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_Rooms.cpp$(PreprocessSuffix) src/Rooms.cpp

./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(ObjectSuffix): src/NewApointmentPage.cpp ./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/src/NewApointmentPage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_NewApointmentPage.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(DependSuffix): src/NewApointmentPage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(DependSuffix) -MM src/NewApointmentPage.cpp

./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(PreprocessSuffix): src/NewApointmentPage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//src_NewApointmentPage.cpp$(PreprocessSuffix) src/NewApointmentPage.cpp


-include ./build-$(ConfigurationName)///*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)



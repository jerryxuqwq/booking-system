##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=AssistantTest
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/jerry/Documents/booking-system
ProjectPath            :=/home/jerry/Documents/booking-system/AssistantTest
IntermediateDirectory  :=../build-$(ConfigurationName)/AssistantTest
OutDir                 :=../build-$(ConfigurationName)/AssistantTest
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jerry
Date                   :=11/17/20
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
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

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
Objects0=../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/AssistantTest/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/AssistantTest/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/AssistantTest"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/AssistantTest"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/AssistantTest/.d:
	@mkdir -p "../build-$(ConfigurationName)/AssistantTest"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(ObjectSuffix): examplewindow.cpp ../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/AssistantTest/examplewindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/examplewindow.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(DependSuffix): examplewindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(DependSuffix) -MM examplewindow.cpp

../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(PreprocessSuffix): examplewindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/AssistantTest/examplewindow.cpp$(PreprocessSuffix) examplewindow.cpp

../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(ObjectSuffix): exampleassistant.cpp ../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/AssistantTest/exampleassistant.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/exampleassistant.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(DependSuffix): exampleassistant.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(DependSuffix) -MM exampleassistant.cpp

../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(PreprocessSuffix): exampleassistant.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/AssistantTest/exampleassistant.cpp$(PreprocessSuffix) exampleassistant.cpp

../build-$(ConfigurationName)/AssistantTest/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/AssistantTest/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jerry/Documents/booking-system/AssistantTest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/AssistantTest/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/AssistantTest/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/AssistantTest/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/AssistantTest/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/AssistantTest/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/AssistantTest//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)



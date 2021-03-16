#pragma once
#include "repo.h"

void InitializeService();

int ServiceAddProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);

int ServiceUpdateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);

int ServiceDeleteProfile(int profileIdNumber);

void ServiceUndoCommand();

void ServiceRedoCommand();

void ServiceUndo();

void ServiceRedo();

DynamicArray* ServiceGetAll();

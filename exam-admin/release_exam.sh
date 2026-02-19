#!/bin/bash

ORG="huji-exams"
TEMPLATE="exam-template-student"

while read username; do
  REPO_NAME="exam-$username"

  echo "Creating repo for $username"

  gh repo create $ORG/$REPO_NAME \
    --private \
    --template $ORG/$TEMPLATE

  gh repo add-collaborator \
    $ORG/$REPO_NAME \
    $username \
    --permission push

done < exam-admin/students.txt

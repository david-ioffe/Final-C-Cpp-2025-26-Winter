#!/bin/bash

ORG="david-ioffe"
TEMPLATE="Final-C-Cpp-2025-26-Winter"

while read username; do
  REPO_NAME="exam-$username"

  echo "Creating repo for $username"

  gh repo create $ORG/$REPO_NAME \
    --private \
    --template $ORG/$TEMPLATE

  gh api -hostname github.cs.huji.ac.il \
    -X PUT \
    repos/$ORG/$REPO_NAME/collaborators/$username \
    -f permission=push

done < exam-admin/students.txt


name: Release Exam

on:
  schedule:
    - cron: '0 13 19 2 *'   # ⚠ שעה ב-UTC (ישראל = UTC+2 בחורף)
  workflow_dispatch:

jobs:
  release:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout admin repo
        uses: actions/checkout@v3

      - name: Install GitHub CLI
        run: |
          sudo apt update
          sudo apt install gh -y

      - name: Authenticate
        run: echo "${{ secrets.ORG_TOKEN }}" | gh auth login --with-token

      - name: Release repos
        run: |
          ORG="huji-exams"
          TEMPLATE="exam-template-student"

          while read username; do

            REPO_NAME="exam-${username}"

            echo "Creating repo for $username"

            gh repo create $ORG/$REPO_NAME \
              --private \
              --template $ORG/$TEMPLATE \
              --confirm

            gh repo add-collaborator \
              $ORG/$REPO_NAME \
              ${username}@cs.huji.ac.il \
              --permission push

          done < exam-admin/students.txt

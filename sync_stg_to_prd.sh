#!/bin/bash

echo "=== Синхронизация stg -> prd ==="

git checkout stg
git pull origin stg

git checkout prd
git pull origin prd

git merge stg -m "Merge stg into prd $(date +'%Y-%m-%d %H:%M:%S')"

TAG_NAME="prd-$(date +'%Y%m%d-%H%M%S')"
git tag $TAG_NAME

git push origin prd
git push origin $TAG_NAME

echo "=== Готово! Тег: $TAG_NAME ==="


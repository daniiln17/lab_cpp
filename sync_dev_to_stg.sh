#!/bin/bash

echo "=== Синхронизация dev -> stg ==="

# Переключаемся на dev и получаем последние изменения
git checkout dev
git pull origin dev

# Переключаемся на stg и получаем последние изменения
git checkout stg
git pull origin stg

# Сливаем dev в stg
git merge dev -m "Merge dev into stg $(date +'%Y-%m-%d %H:%M:%S')"

# Создаём тег с меткой времени
TAG_NAME="stg-$(date +'%Y%m%d-%H%M%S')"
git tag $TAG_NAME

# Отправляем изменения на GitHub
git push origin stg
git push origin $TAG_NAME

echo "=== Готово! Тег: $TAG_NAME ==="

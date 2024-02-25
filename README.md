
# NSTU-Programming

Здарова, щас будем учиться пользоваться этим репозиторием.

## Contributing

1) В ветке `main` мы ничего не делаем, работаем либо в существующей ветке, либо создаём новую `(new-branch)`.
2) Изменения в тупую не мерджим, создаём `pull request`, описываем изменения если нужно и открываем его.
3) После `pull request` ветку не удаляем, если возможно, что в ней будут изменения, в ином случае сносим.
4) **Ультражелательно всё запихивать в отдельные модули и связывать с мейн функцией**, но я это если что сам сделаю.
## Частые вопросы

- [А как..?](#А-как)
- [Не создаётся новая ветка](#Не-создаётся-новая-ветка)
- [Что писать в коммитах](#Что-писать-в-коммитах)
- [Я создал коммит, но забыл что-то добавить](#Я-создал-коммит,-но-забыл-чет-добавить)
- [Как переключаться между ветками](#Как-переключаться-между-ветками)
- [А что за rebase и cherry-pick](#А-что-за-rebase-и-cherry-pick)
- [Как получить новые изменения](#Как-получить-новые-изменения)
- [Как часто мне коммитить мои изменения](#Как-часто-мне-коммитить-мои-изменения)

## А как
Спрашивай что угодно, не стесняйся.
## Не создаётся новая ветка
Для начала проверь, что у тебя закоммичены все твои текущие изменения
## Что писать в коммитах
Строго на английском и только описание новых изменений. **Без мата!!!**
## Я создал коммит но забыл чет добавить
Есть команда `git commit --amend`.
## Как переключаться между ветками
Есть команда `git checkout <branch>`.
## А что за rebase и cherry-pick
Страшные вещи, пока не трогай
## Как получить новые изменения
1) `git --checkout <branch>`
2) `git --fetch` (либо просто `Update selected`).
## Как часто мне коммитить мои изменения
Лучше лишний раз, чем ниразу.

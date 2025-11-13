# ShopPlatform - Distributed System Project

Projekt demonstracyjny systemu rozproszonego zbudowanego z wykorzystaniem .NET Aspire, zawierający mikrousługi, bazę danych PostgreSQL, cache Redis oraz frontend Blazor.

## 📋 Spis treści
- [Opis projektu](#opis-projektu)
- [Architektura](#architektura)
- [Technologie](#technologie)
- [Wymagania](#wymagania)
- [Instalacja i uruchomienie](#instalacja-i-uruchomienie)
- [Struktura projektu](#struktura-projektu)
- [Endpointy API](#endpointy-api)
- [Wdrożenie](#wdrożenie)

## 🎯 Opis projektu

ShopPlatform to aplikacja demonstrująca możliwości .NET Aspire w tworzeniu systemów rozproszonych. Zawiera:
- **Shop.Api** - API produktów z obsługą bazy danych PostgreSQL
- **ShopPlatform.ApiService** - Dodatkowe API z danymi pogodowymi
- **ShopPlatform.Web** - Frontend Blazor Server z interaktywnymi komponentami
- **ShopPlatform.AppHost** - Orkiestrator zarządzający wszystkimi serwisami
- **ShopPlatform.ServiceDefaults** - Wspólne ustawienia (telemetria, resilience, health checks)

## 🏗️ Architektura

```
┌─────────────────────┐
│   Blazor Frontend   │ (ShopPlatform.Web)
│   (Port: 5xxx)      │
└──────────┬──────────┘
           │
           ├──────────────┐
           │              │
           ▼              ▼
┌──────────────┐  ┌──────────────┐
│  Shop.Api    │  │  ApiService  │
│  (Products)  │  │  (Weather)   │
└──────┬───────┘  └──────────────┘
       │
       ├──────────────┐
       │              │
       ▼              ▼
┌──────────┐  ┌──────────────┐
│  Redis   │  │ PostgreSQL   │
│  Cache   │  │ (productsdb) │
└──────────┘  └──────────────┘
```

### Komponenty systemu:
- **Frontend**: Blazor Server z SignalR WebSocket
- **API Gateway**: Service Discovery dla automatycznego routingu
- **Cache**: Redis dla Output Cache
- **Baza danych**: PostgreSQL z Entity Framework Core
- **Monitoring**: OpenTelemetry + Aspire Dashboard
- **Resilience**: Polly (retry, circuit breaker, timeout)

## 💻 Technologie

- **.NET 9.0** - Platforma aplikacyjna
- **ASP.NET Core** - Framework webowy
- **Blazor Server** - Interaktywny UI
- **.NET Aspire** - Orkiestracja systemów rozproszonych
- **Entity Framework Core** - ORM dla bazy danych
- **PostgreSQL** - Relacyjna baza danych
- **Redis** - In-memory cache
- **OpenTelemetry** - Telemetria i monitoring
- **OpenAPI/Swagger** - Dokumentacja API
- **Polly** - Resilience patterns

## ⚙️ Wymagania

### Wymagane:
- [.NET 9.0 SDK](https://dotnet.microsoft.com/download/dotnet/9.0)
- [Docker Desktop](https://www.docker.com/products/docker-desktop) (dla PostgreSQL i Redis)

### Opcjonalne:
- [Visual Studio 2022](https://visualstudio.microsoft.com/) lub [VS Code](https://code.visualstudio.com/)
- [Azure Developer CLI](https://learn.microsoft.com/azure/developer/azure-developer-cli/install-azd) (dla wdrożenia na Azure)
- [kubectl](https://kubernetes.io/docs/tasks/tools/) (dla Kubernetes)

## 🚀 Instalacja i uruchomienie

### 1. Sklonuj repozytorium
```powershell
git clone <repository-url>
cd systemy_rozproszone
```

### 2. Uruchom projekt lokalnie
```powershell
# Uruchom Aspire AppHost (automatycznie startuje wszystkie serwisy)
dotnet run --project ShopPlatform.AppHost
```

### 3. Otwórz aplikację
- **Aspire Dashboard**: http://localhost:15000 (monitoring, logi, metryki)
- **Blazor Frontend**: http://localhost:5xxx (port wyświetlony w dashboardzie)
- **Shop.Api Swagger**: http://localhost:5xxx/swagger
- **ApiService Swagger**: http://localhost:5xxx/swagger

## 📁 Struktura projektu

```
systemy_rozproszone/
├── Shop.Api/                      # API produktów
│   ├── Program.cs                 # Konfiguracja aplikacji
│   ├── Data/
│   │   └── ProductsContext.cs     # Kontekst EF Core
│   └── Shop.Api.csproj
│
├── ShopPlatform.ApiService/       # API pogody
│   ├── Program.cs
│   └── ShopPlatform.ApiService.csproj
│
├── ShopPlatform.Web/              # Frontend Blazor
│   ├── Program.cs
│   ├── Components/
│   │   ├── Pages/                 # Strony Blazor
│   │   │   ├── Home.razor
│   │   │   ├── Counter.razor
│   │   │   ├── Weather.razor
│   │   │   └── Products.razor
│   │   └── Layout/                # Layout aplikacji
│   ├── ProductsApiClient.cs
│   └── WeatherApiClient.cs
│
├── ShopPlatform.AppHost/          # Orkiestrator Aspire
│   ├── AppHost.cs                 # Definicja infrastruktury
│   └── ShopPlatform.AppHost.csproj
│
├── ShopPlatform.ServiceDefaults/  # Wspólne ustawienia
│   ├── Extensions.cs              # Health checks, telemetria
│   └── ShopPlatform.ServiceDefaults.csproj
│
├── azure.yaml                     # Konfiguracja Azure Developer CLI
├── Generate-K8s-Manifests.ps1    # Skrypt generowania Kubernetes
└── Setup-Azure-Deployment.ps1    # Skrypt wdrożenia Azure
```

## 🔌 Endpointy API

### Shop.Api (Produkty)
- `GET /products` - Lista produktów z bazy danych
- `GET /weatherforecast` - Przykładowe prognozy pogody
- `GET /health` - Health check
- `GET /alive` - Liveness check
- `GET /swagger` - Dokumentacja Swagger (tylko Development)

### ShopPlatform.ApiService (Pogoda)
- `GET /weatherforecast` - Generowanie prognoz pogody
- `GET /health` - Health check
- `GET /alive` - Liveness check

### ShopPlatform.Web (Frontend)
- `/` - Strona główna
- `/counter` - Licznik (demo Blazor)
- `/weather` - Prognozy pogody (z cache)
- `/products` - Lista produktów (z cache)

## 🌐 Wdrożenie

### Azure (Azure Developer CLI)
```powershell
# Uruchom skrypt pomocniczy
.\Setup-Azure-Deployment.ps1

# Zaloguj się do Azure
azd auth login

# Zainicjalizuj środowisko
azd env new dev

# Wdróż na Azure (provision + deploy)
azd up
```

### Kubernetes
```powershell
# Wygeneruj manifesty Kubernetes
.\Generate-K8s-Manifests.ps1

# Deploy do Kubernetes
kubectl apply -f .\k8s\
```

### Docker Compose (lokalne środowisko)
```powershell
# Build i uruchom
docker-compose up -d
```

## 🧪 Testowanie

### Resilience Testing
Endpoint `/products` w Shop.Api losowo rzuca wyjątki (25% żądań), aby przetestować polityki resilience (retry, circuit breaker).

### Health Checks
Sprawdź status aplikacji:
```powershell
curl http://localhost:5xxx/health
curl http://localhost:5xxx/alive
```

## 📊 Monitoring

### Aspire Dashboard
Otwórz http://localhost:15000 aby zobaczyć:
- **Traces** - Distributed tracing żądań
- **Metrics** - Metryki wydajności (CPU, pamięć, HTTP)
- **Logs** - Logi strukturalne ze wszystkich serwisów
- **Resources** - Status kontenerów (Redis, PostgreSQL)

### OpenTelemetry
Projekt używa OpenTelemetry do eksportowania danych telemetrycznych do Aspire Dashboard.

## 🔒 Bezpieczeństwo

- **HTTPS**: Przekierowanie HTTP → HTTPS
- **HSTS**: HTTP Strict Transport Security (30 dni)
- **Antiforgery**: Ochrona przed CSRF
- **Health Checks**: Tylko w środowisku Development (produkcja wymaga autoryzacji)

## 📝 Uwagi

- **Środowisko Development**: Swagger, Health Checks, szczegółowe błędy są dostępne
- **Środowisko Production**: Ograniczona dokumentacja, ogólne komunikaty błędów
- **Redis**: Wymagany do Output Cache (aplikacja nie wystartuje bez niego)
- **PostgreSQL**: Wymagany do Shop.Api (migracje uruchamiane przy starcie)

## 🤝 Wkład

Projekt demonstracyjny dla celów edukacyjnych - systemy rozproszone z .NET Aspire.

## 📄 Licencja

MIT License - możesz używać kodu w projektach komercyjnych i niekomercyjnych.

---

**Autor**: Projekt demonstracyjny  
**Data**: Listopad 2025  
**Framework**: .NET 9.0 + Aspire
